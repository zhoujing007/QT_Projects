#include "camera.h"
#include <QObject>
#include <QImage>
#include <QDebug>
#include <time.h>
#include <QSettings>
//#define USE_DAHENG 1

#ifndef USE_DAHENG
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/features2d.hpp>
#include <thread>

cv::VideoCapture capture;
std::thread thread_video;
#endif

#include "QApplication"
#include "QTextCodec"

///< 判断返回值宏定义
#pragma execution_character_set("utf-8")

#define  FALSE_RETURN_FALSE(P)\
    if (!P)\
    {\
        return false;\
    }


#define VERIFY_STATUS_RET(status) \
    if (status != GX_STATUS_SUCCESS) \
    {\
        return status; \
    }

int white_counter = 0;

Camera::~Camera() {
    if (is_open_) {
        close();
    }

    delete []raw_data_;
    delete []rgb_data_;
}


bool Camera::open() {
    if (is_use_C920_) {
        capture.open(0);
        return true;
    }

    //     if (is_open_) {
    //         return true;
    //     }
    //相机设备错误码
    GX_STATUS camera_status = GX_STATUS_SUCCESS;

    //初始化api
    camera_status = GXInitLib();
    FALSE_RETURN_FALSE(status_verify(camera_status));

    //相机打开参数
    GX_OPEN_PARAM camera_param;
    camera_param.accessMode = GX_ACCESS_EXCLUSIVE;
    camera_param.openMode = GX_OPEN_INDEX;
    camera_param.pszContent = "1";

    //枚举设备
    uint32_t dev_num = 0;
    camera_status = GXUpdateDeviceList(&dev_num, 1000);

    FALSE_RETURN_FALSE(status_verify(camera_status));

    //判断设备数量
    if (dev_num <= 0) {
        last_error_str_ = QObject::tr("没有发现设备");
        return false;
    }

    //打开设备
    camera_status = GXOpenDevice(&camera_param, &camera_handle_);
    FALSE_RETURN_FALSE(status_verify(camera_status));

    //初始化设备
    camera_status = init_device();
    FALSE_RETURN_FALSE(status_verify(camera_status));

    //获取设备属性
    camera_status = get_device_param();
    FALSE_RETURN_FALSE(status_verify(camera_status));

    image_improve_param();

    //为原始图像数据申请空间
    raw_data_ = new uchar[image_size_];
    rgb_data_ = new uchar[image_size_ * 3];

    //注册回调
    camera_status = GXRegisterCaptureCallback(camera_handle_, this, camera_call_back);
    FALSE_RETURN_FALSE(status_verify(camera_status));
    //注册掉线回调
    //定义掉线回调函数句柄

    camera_status = GXRegisterDeviceOfflineCallback(camera_handle_, this, offline_call_back, &offline_event_);

    is_open_ = true;
    return true;
}

#ifndef USE_DAHENG

bool c920_run = true;
void c920() {
    CvSize size(1292, 964);
    IplImage* image = cvCreateImage(size, IPL_DEPTH_8U, 3);
    image->origin = 1;

    cv::Mat frame;
    cv::Mat big_frame;
    cv::Mat frame2;
    while (c920_run) {

        capture.read(frame);
        if (frame.empty()) {
            continue;
        }
        frame2 = frame.clone();
        //         LogInfo("camera:fps = %d", capture.get(cv::CAP_PROP_FPS));
        //         LogInfo("camera:fps = %d", capture.get(cv::CAP_PROP_FPS));
        //         LogInfo("camera:fps = %d", capture.get(cv::CAP_PROP_FPS));
        resize(frame2, big_frame, size);
        *image = big_frame;
        cvFlip(image);
        //Camera::instance()->emit_data((uchar*)image->imageData, 1292, 964);
        Camera::instance()->out_callback_((uchar*)image->imageData, 1292, 964);
        // std::this_thread::sleep_for(std::chrono::milliseconds(1));
        // int cmd = cvWaitKey(33);
    }
}
#endif

bool Camera::start_collection() {

    if (is_use_C920_) {
        c920_run = true;
        thread_video = std::thread(c920);
        return true;
    } else {
        if (!is_open_) {
            return false;
        }
    }

    GX_STATUS gx_status = GX_STATUS_ERROR;



    //发开始采集命令
    gx_status = GXSendCommand(camera_handle_, GX_COMMAND_ACQUISITION_START);
    FALSE_RETURN_FALSE(status_verify(gx_status));
    is_start_ = true;
    return true;
    //m_bIsSnap = TRUE;
}

bool Camera::stop_collection() {
    if (is_use_C920_) {
        c920_run = false;
        return true;
    } else {
        GXSendCommand(camera_handle_, GX_COMMAND_ACQUISITION_STOP);
        is_start_ = false;
        return true;
    }
}

QString Camera::last_error() {
    return last_error_str_;
}

void Camera::close() {
    if (is_use_C920_) {
        if (thread_video.joinable()) {
            c920_run = false;
            thread_video.join();
            capture.release();
        }
    } else {
        if (is_open_) {
            GX_STATUS gx_status = GX_STATUS_SUCCESS;

            // 发送停止采集命令
            if (is_start_) {
                stop_collection();
            }


            // 注销回调
            gx_status = GXUnregisterCaptureCallback(camera_handle_);
            GXUnregisterDeviceOfflineCallback(camera_handle_, offline_event_);


            //关闭设备
            gx_status = GXCloseDevice(camera_handle_);
            //关闭api
            gx_status = GXCloseLib();

            is_open_ = false;
        }
    }
}


GX_STATUS Camera::init_device() {
    GX_STATUS gx_status = GX_STATUS_SUCCESS;

    //设置采集模式连续采集
    gx_status = GXSetEnum(camera_handle_, GX_ENUM_ACQUISITION_MODE, GX_ACQ_MODE_CONTINUOUS);
    VERIFY_STATUS_RET(gx_status);

    // 图像数据格式设置为8Bit
    gx_status = set_pixel_format();

    //关闭自动增益
    gain_auto_ = GX_GAIN_AUTO_OFF;
    gx_status = GXSetEnum(camera_handle_, GX_ENUM_GAIN_AUTO, gain_auto_);


    //ui.arg16->setText(GetConfigValue("SysConfig", "Parameters", "arg16").toString());
    exposure_ = "固定";
    buffer_frame_ = 30;
    if (sampling_30_ == true) {
        gain_ = 400;
        exposure_time_ = 33333;// 40000); //33333//39062);//50000);//33333);
    } else {
        gain_ = 333;
        exposure_time_ = 40000;
    }
    gx_status = GXSetFloat(camera_handle_, GX_FLOAT_GAIN, gain_);
    gx_status = GXSetFloat(camera_handle_, GX_FLOAT_EXPOSURE_TIME, exposure_time_);
    auto_white_balance_ = GX_BALANCE_WHITE_AUTO_CONTINUOUS;
    gx_status = GXSetEnum(camera_handle_, GX_ENUM_BALANCE_WHITE_AUTO, auto_white_balance_);

    acquisition_speed_level_ = 12;
    gx_status = GXSetEnum(camera_handle_, GX_INT_ACQUISITION_SPEED_LEVEL, acquisition_speed_level_);



    int64_t nBinningH = 1;

    int64_t nBinningV = 1;

    int64_t nDecimationH = 1;

    int64_t nDecimationV = 1;


    gx_status = GXSetInt(camera_handle_, GX_INT_DECIMATION_HORIZONTAL, nDecimationH);

    gx_status = GXSetInt(camera_handle_, GX_INT_DECIMATION_VERTICAL, nDecimationV);



    GX_FLOAT_RANGE autoGainMinRange;

    GX_FLOAT_RANGE autoGainMaxRange;

    gx_status = GXSetEnum(camera_handle_, GX_ENUM_GAIN_SELECTOR, GX_GAIN_SELECTOR_ALL);


    gx_status = GXGetFloatRange(camera_handle_, GX_FLOAT_AUTO_GAIN_MIN, &autoGainMinRange);

    gx_status = GXGetFloatRange(camera_handle_, GX_FLOAT_AUTO_GAIN_MAX, &autoGainMaxRange);
    //
    //     QString path = QApplication::applicationDirPath();
    //     camera_para_save(path + "/camera.ini");

    return gx_status;
}


// ---------------------------------------------------------------------------------
/**
\brief   设置相机的数据格式为8bit

\return  gx_status GX_STATUS_SUCCESS:设置成功，其它:设置失败
*/
// ----------------------------------------------------------------------------------
GX_STATUS Camera::set_pixel_format() {
    GX_STATUS gx_status = GX_STATUS_SUCCESS;
    int64_t   nPixelSize = 0;
    uint32_t  nEnmuEntry = 0;
    size_t    nBufferSize = 0;
    BOOL      bIs8bit = TRUE;

    GX_ENUM_DESCRIPTION*  pEnumDescription = NULL;
    GX_ENUM_DESCRIPTION*  pEnumTemp = NULL;

    // 获取像素点大小
    gx_status = GXGetEnum(camera_handle_, GX_ENUM_PIXEL_SIZE, &nPixelSize);
    VERIFY_STATUS_RET(gx_status);

    // 判断为8bit时直接返回,否则设置为8bit
    if (nPixelSize == GX_PIXEL_SIZE_BPP8) {
        return GX_STATUS_SUCCESS;
    } else {
        // 获取设备支持的像素格式枚举数
        gx_status = GXGetEnumEntryNums(camera_handle_, GX_ENUM_PIXEL_FORMAT, &nEnmuEntry);
        VERIFY_STATUS_RET(gx_status);

        // 为获取设备支持的像素格式枚举值准备资源
        nBufferSize = nEnmuEntry * sizeof(GX_ENUM_DESCRIPTION);
        pEnumDescription = new GX_ENUM_DESCRIPTION[nEnmuEntry];

        // 获取支持的枚举值
        gx_status = GXGetEnumDescription(camera_handle_, GX_ENUM_PIXEL_FORMAT, pEnumDescription, &nBufferSize);
        if (gx_status != GX_STATUS_SUCCESS) {
            if (pEnumDescription != NULL) {
                delete[]pEnumDescription;
                pEnumDescription = NULL;
            }

            return gx_status;
        }

        // 遍历设备支持的像素格式,设置像素格式为8bit,
        // 如设备支持的像素格式为Mono10和Mono8则设置其为Mono8
        for (uint32_t i = 0; i < nEnmuEntry; i++) {
            if ((pEnumDescription[i].nValue & GX_PIXEL_8BIT) == GX_PIXEL_8BIT) {
                gx_status = GXSetEnum(camera_handle_, GX_ENUM_PIXEL_FORMAT, pEnumDescription[i].nValue);
                break;
            }
        }

        // 释放资源
        if (pEnumDescription != NULL) {
            delete[]pEnumDescription;
            pEnumDescription = NULL;
        }
    }

    return gx_status;
}


//----------------------------------------------------------------------------------
/**
\brief  获取设备的宽高等属性信息

\return 无
*/
//----------------------------------------------------------------------------------
GX_STATUS Camera::get_device_param() {
    GX_STATUS gx_status = GX_STATUS_ERROR;
    bool      bColorFliter = false;

    // 获取图像大小
    gx_status = GXGetInt(camera_handle_, GX_INT_PAYLOAD_SIZE, &image_size_);
    VERIFY_STATUS_RET(gx_status);

    // 获取宽度
    gx_status = GXGetInt(camera_handle_, GX_INT_WIDTH, &image_width_);
    VERIFY_STATUS_RET(gx_status);

    //判断相机是否支持bayer格式
    gx_status = GXIsImplemented(camera_handle_, GX_ENUM_PIXEL_COLOR_FILTER, &color_filter_);
    VERIFY_STATUS_RET(gx_status);
    if (color_filter_) {
        gx_status = GXGetEnum(camera_handle_, GX_ENUM_PIXEL_COLOR_FILTER, &pixel_color_filter_);
        VERIFY_STATUS_RET(gx_status);
    }

    //判断相机是否支持白平衡通道
    gx_status = GXIsImplemented(camera_handle_, GX_ENUM_BALANCE_RATIO_SELECTOR, &balance_ratio_selector_);
    VERIFY_STATUS_RET(gx_status);

    // 获取高度
    gx_status = GXGetInt(camera_handle_, GX_INT_HEIGHT, &image_height_);

    return gx_status;
}


// -------------------------------------------------------------------------------- -
/**
\brief   获取图像质量提升参数

\return  无
*/
//----------------------------------------------------------------------------------
void Camera::image_improve_param() {
    if (!color_filter_) {
        return;
    }

    GX_STATUS emStatus = GX_STATUS_SUCCESS;
    VxInt32  nStatus = DX_OK;

    // 获取对比度参数
    emStatus = GXGetInt(camera_handle_, GX_INT_CONTRASTPARAM, &m_nContrast);
    status_verify(emStatus);

    // 获取颜色校正参数
    emStatus = GXGetInt(camera_handle_, GX_INT_COLORCORRECTIONPARAM, &m_nColorCorrection);
    status_verify(emStatus);

    // 获取Gamma参数
    emStatus = GXGetFloat(camera_handle_, GX_FLOAT_GAMMAPARAM, &m_dGamma);
    status_verify(emStatus);

    do {
        // 获取Gamma查找表长度
        nStatus = DxGetGammatLut(m_dGamma, NULL, &m_nLutLength);
        if (nStatus != DX_OK) {
            break;
        }

        m_pGammaLut = new BYTE[m_nLutLength];
        if (m_pGammaLut == NULL) {
            nStatus = DX_NOT_ENOUGH_SYSTEM_MEMORY;
            break;
        }

        // 计算Gamma查找表
        nStatus = DxGetGammatLut(m_dGamma, m_pGammaLut, &m_nLutLength);
        if (nStatus != DX_OK) {
            break;
        }

        // 获取对比度查找表长度
        nStatus = DxGetContrastLut((int)m_nContrast, NULL, &m_nLutLength);
        if (nStatus != DX_OK) {
            break;
        }

        m_pContrastLut = new BYTE[m_nLutLength];
        if (m_pContrastLut == NULL) {
            nStatus = DX_NOT_ENOUGH_SYSTEM_MEMORY;
            break;
        }

        // 计算对比度查找表
        nStatus = DxGetContrastLut((int)m_nContrast, m_pContrastLut, &m_nLutLength);
        if (nStatus != DX_OK) {
            break;
        }

    } while (0);

    // 设置查找表失败，释放资源
    if (nStatus != DX_OK) {
        if (m_pGammaLut != NULL) {
            delete[] m_pGammaLut;
            m_pGammaLut = NULL;
        }
        if (m_pContrastLut != NULL) {
            delete[] m_pContrastLut;
            m_pContrastLut = NULL;
        }
        last_error_str_ = QObject::tr("获取图像处理查找表参数失败！");
        return;
    }
}

void  Camera::camera_call_back(GX_FRAME_CALLBACK_PARAM* param) {
    clock_t start = clock();
    Camera* camera = (Camera*)param->pUserParam;
    if (param->status == GX_FRAME_STATUS_SUCCESS) {
        int size = param->nWidth * param->nHeight * 3;
        if (!camera->is_open_) {
            return;
        }
        memcpy(camera->raw_data_, param->pImgBuf, param->nImgSize);
        DxRaw8toRGB24(camera->raw_data_,
                      camera->rgb_data_,
                      camera->image_width_,
                      camera->image_height_,
                      RAW2RGB_NEIGHBOUR,
                      DX_PIXEL_COLOR_FILTER(camera->pixel_color_filter_),
                      TRUE);

        if (camera->image_improve_) {
            //提升图像质量
            DxImageImprovment(camera->rgb_data_
                              , camera->rgb_data_
                              , (VxUint32)(param->nWidth)
                              , (VxUint32)(param->nHeight)
                              , camera->m_nColorCorrection
                              , camera->m_pContrastLut
                              , camera->m_pGammaLut);
        }


        //白平衡延时关闭，延时120帧图像
        white_counter++;
        if (white_counter > 121)
            white_counter = 121;
        if (white_counter == 120) {
            camera->auto_white_balance_ = GX_BALANCE_WHITE_AUTO_OFF;
            GXSetEnum(camera->camera_handle_, GX_ENUM_BALANCE_WHITE_AUTO, camera->auto_white_balance_);
        }


        camera->out_callback_(camera->rgb_data_, param->nWidth, param->nHeight);
        clock_t end  = clock();
        //qDebug() << "camera call back used time = " << end - start;
    } else {
        camera->status_verify(param->status);
    }
}

void Camera::set_out_callback(callback_func func) {
    out_callback_ = func;
}

bool Camera::status_verify(GX_STATUS& status) {
    if (status != GX_STATUS_SUCCESS) {
        GX_STATUS status = GX_STATUS_SUCCESS;

        GX_STATUS error_code = GX_STATUS_SUCCESS;

        char* error_buf = NULL;

        size_t n_size = 0;

        //传入NULL指针，获取实际长度，然后申请buffer再获取描述信息

        GXGetLastError(&error_code, NULL, &n_size);

        error_buf = new char[n_size];

        status = GXGetLastError(&error_code, error_buf, &n_size);
        if (status != GX_STATUS_SUCCESS) {
            last_error_str_ = QString("GXGetLastError接口调用失败");
        } else {
            last_error_str_ = QString::fromLocal8Bit(error_buf);
        }
        qDebug() << last_error_str_;
        delete error_buf;


        return false;
    }
    return true;
}

void __stdcall Camera::offline_call_back(void* param) {
    qDebug() << "掉线了";
}

void Camera::camera_para_save(QString save_path) {
    QString txt_path = save_path;
    //     QSettings* configIniWrite = new QSettings(txt_path, QSettings::IniFormat);
    //     configIniWrite->clear();
    //     configIniWrite->setIniCodec(QTextCodec::codecForName("UTF-8"));
    QFile file(txt_path);
    if (!file.open(QFile::ReadWrite)) {
        LogError("相机参数写入文件失败");
    }
    QString camera_para;
    auto convert = [](const QString & para_name, const QString & para_value) {
        QString str = para_name;
        //str.sprintf("%.2f", para_value);
        str.append(":") ;
        str.append(para_value);
        return str;
    };
    auto write_value = [&]() {
        file.write(camera_para.toLocal8Bit());
        file.write("\r\n");
    };
    QStringList camera_para_name;
    camera_para_name << "自动增益" << "自动白平衡" << "采集速度级别" << "曝光" << "帧率fps" << "增益" << "曝光时间"  << "图像大小"
                     << "图像宽度" << "Bayer格式" << "图像高度" << "对比度参数" << "颜色校正参数" << "Gamma参数";

    QStringList camera_para_value;
    camera_para_value << QObject::tr("%1").arg(gain_auto_) << QObject::tr("%1").arg(auto_white_balance_) << QObject::tr("%1").arg(acquisition_speed_level_)
                      << exposure_ << QObject::tr("%1").arg(buffer_frame_) << QObject::tr("%1").arg(gain_) << QObject::tr("%1").arg(exposure_time_) << QObject::tr("%1").arg(image_size_)
                      << QObject::tr("%1").arg(image_width_) << QObject::tr("%1").arg(pixel_color_filter_) << QObject::tr("%1").arg(image_height_)
                      << QObject::tr("%1").arg(m_nContrast) << QObject::tr("%1").arg(m_nColorCorrection) << QObject::tr("%1").arg(m_dGamma);
    //写入相机数据
    file.write(QString("相机参数").toLocal8Bit());
    file.write("\r\n");
    for (int i = 0; i < camera_para_name.size(); i++) {
        camera_para = convert(camera_para_name.at(i), camera_para_value.at(i));
        write_value();

    }
    file.close();
    LogInfo("结果数据写入成功");

    //     for (int i = 0 ; i < camera_para_name.size(); i++) {
    //         configIniWrite->setValue(/*camera_para_name.at(i)*/"qwe/asd", camera_para_value.at(i));
    //     }

    //写入完成后删除指针
    //delete configIniWrite;
}


