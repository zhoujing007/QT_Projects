
#ifndef CAMERA_H
#define CAMERA_H
#include <QString>
#include <GxIAPI.h>
#include <DxImageProc.h>
#include <QImage>
#include "CommonFuncs.h"
#include <functional>
#include "CameraInterface.h"

//定义外部接受图像数据的函数指针
using callback_func = std::function<void(uchar*, const int&, const int&)>;

/**@brief 照相机类定义，对大恒相机的基本功能进行了封装*/
class Camera : public CameraInterface {
    SINGLETON(Camera)
private:
    Camera() {};
    ~Camera();

public:
    /*
    * @brief 打开相机
    * @return true 标识打开成功，false 表示打开失败
    * @note 当打开失败时，可调用last_error()函数进行失败信息查看
    */
    bool open();

    /*
    * @brief 开始采集命令
    * @return true 开始采集成功，false 开始采集失败
    * @note 采集失败时，可调用last_error()函数进行失败信息查看
    */
    bool start_collection();

    /*
    * @brief 停止采集命令
    * @return true 停止采集成功，false 停止采集失败
    * @note 停止采集失败时，可调用last_error()函数进行失败信息查看
    */
    bool stop_collection();

    /*
    * @brief 错误信息获取
    * @return QString 错误信息字符串
    */
    QString last_error();

    /**@brief 关闭相机*/
    void close();

    void set_out_callback(callback_func func);

    void set_ipcurl(QString camera_url) {};
private:

    /*
    * @brief 相机状态检测，以及错误信息生成
    */
    bool status_verify(GX_STATUS& status);

    /*
    * @brief 相机初始化
    */
    GX_STATUS init_device();

    /*
    * @brief 相机采集数据格式设置
    */
    GX_STATUS set_pixel_format();

    /*
    * @brief 获取相机基本参数
    */
    GX_STATUS get_device_param();

    /*
    * @brief 相机图像提升参数
    */
    void image_improve_param();

    /*
    * @brief 相机回调参数
    */
    static void __stdcall camera_call_back(GX_FRAME_CALLBACK_PARAM* param);

    /*
    * @brief:   相机掉线回调
    * @param:   void * param
    * @return:  void __stdcall
    */
    static void __stdcall offline_call_back(void* param);

    void camera_para_save(QString save_path);

public:
    QString             last_error_str_;            ///< 错误信息
    GX_DEV_HANDLE       camera_handle_ = nullptr;   ///< 相机设备句柄
    bool                sampling_30_ = true;        ///< 采样率
    bool                image_improve_ = true;      ///< 是否提升图像质量

    int64_t             gain_auto_;                 ///< 自动增益
    double              gain_;                      ///< 增益
    double              exposure_time_;             ///< 曝光时间
    int64_t             acquisition_speed_level_;   ///< 采集速度级别
    QString             exposure_;                  ///< 曝光
    int64_t             buffer_frame_;              ///< 帧率FPS


    int64_t             image_size_;                ///< 图像大小
    int64_t             image_height_;              ///< 原始图像高
    int64_t             image_width_;               ///< 原始图像宽
    int64_t             pixel_color_filter_;        ///< Bayer格式
    int64_t             auto_white_balance_;        ///< 自动白平衡当前选项
    bool                color_filter_;              ///< 标识是否支持彩色
    bool                balance_ratio_selector_;    ///< 记录当前的白平衡通道


    int64_t             m_nContrast;                ///< 对比度值
    int64_t             m_nColorCorrection = 0;     ///< 颜色校正值
    double              m_dGamma;                   ///< Gammma值
    int                 m_nLutLength;               ///< 查找表长度
    BYTE*               m_pGammaLut;                ///< Gamma查找表
    BYTE*               m_pContrastLut;             ///< 对比度查找表

    bool                is_open_ = false;           ///< 相机是否打开
    bool                is_start_ = false;          ///< 相机是否开始采集

    uchar*              raw_data_;                  ///< 相机原始数据
    uchar*              rgb_data_;                  ///< rgb数据，相机的到的数据十一(B,G,R)顺序存储的
public:

    callback_func      out_callback_ = nullptr;
    GX_EVENT_CALLBACK_HANDLE offline_event_;        ///定义掉线回调函数句柄
};


#endif