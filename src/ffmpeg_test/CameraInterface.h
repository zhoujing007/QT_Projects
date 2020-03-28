#pragma once


#include <QString>
#include "CommonFuncs.h"
#include <functional>

//定义外部接受图像数据的函数指针
using callback_func = std::function<void(uchar*, const int&, const int&)>;

enum CameraType {
    TypeUVCcamera,
    TypeIpcCamera,
};

class CameraInterface {
public:
    CameraInterface() {};
    ~CameraInterface() {};

    /*
    * @brief 打开相机
    * @return true 标识打开成功，false 表示打开失败
    * @note 当打开失败时，可调用last_error()函数进行失败信息查看
    */
    virtual bool open() = 0;

    /*
    * @brief 开始采集命令
    * @return true 开始采集成功，false 开始采集失败
    * @note 采集失败时，可调用last_error()函数进行失败信息查看
    */
    virtual bool start_collection() = 0;

    /*
    * @brief 停止采集命令
    * @return true 停止采集成功，false 停止采集失败
    * @note 停止采集失败时，可调用last_error()函数进行失败信息查看
    */
    virtual bool stop_collection() = 0;

    /*
    * @brief 错误信息获取
    * @return QString 错误信息字符串
    */
    virtual QString last_error() = 0;

    /**@brief 关闭相机*/
    virtual void close() = 0;


    virtual void set_out_callback(callback_func func) = 0;

    virtual void set_ipcurl(QString camera_url) = 0;

    static CameraInterface* get_camera(CameraType camera_type);


public:
    callback_func      out_callback_ = nullptr;

    int64_t image_width_ = 1292;
    int64_t image_height_ = 964;
    int64_t             m_nContrast;                ///< 对比度值
    int64_t             m_nColorCorrection = 0;     ///< 颜色校正值
    double              m_dGamma;                   ///< Gammma值
    int                 m_nLutLength;               ///< 查找表长度
    unsigned char*      m_pGammaLut;                ///< Gamma查找表
    unsigned char*      m_pContrastLut;             ///< 对比度查找表

    bool                is_use_C920_ = false;

private:

};
