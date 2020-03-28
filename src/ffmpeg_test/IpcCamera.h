#pragma once
#include "CameraInterface.h"

/*保存网络流的流程主要有以下步骤：
第一步：注册所有的组件（编解码、滤镜特效处理库、封装格式处理库、工具库、音频采样数据格式转换库、视频像素数据格式转换等等...）
第二步：获取视频流的封装信息，查找视频和音频流的位置
第三步：查找视频和音频解码器id，根据解码器id打开解码器
第四步：创建输出流并拷贝流上下文信息
第五步：循环读取网络流，解码packet并写入本地
第六步：关闭解码器释放内存
*/

class IpcCameraPrivate;
class IpcCamera : public CameraInterface {
    SINGLETON(IpcCamera)
public:
    IpcCamera();
    ~IpcCamera();


    virtual bool open();


    virtual bool start_collection();


    virtual bool stop_collection();


    virtual QString last_error();


    virtual void close();


    virtual void set_out_callback(callback_func func);

    void set_ipcurl(QString ipcurl);

private:

    /*
    * @brief 相机回调参数
    */
    static void* camera_call_back(void* data, void** p_pixels);

public:
private:
    IpcCameraPrivate* private_ptr_ = nullptr;  ///< 私有数据结构
};
