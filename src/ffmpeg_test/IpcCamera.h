#pragma once
#include "CameraInterface.h"

/*������������������Ҫ�����²��裺
��һ����ע�����е����������롢�˾���Ч����⡢��װ��ʽ����⡢���߿⡢��Ƶ�������ݸ�ʽת���⡢��Ƶ�������ݸ�ʽת���ȵ�...��
�ڶ�������ȡ��Ƶ���ķ�װ��Ϣ��������Ƶ����Ƶ����λ��
��������������Ƶ����Ƶ������id�����ݽ�����id�򿪽�����
���Ĳ����������������������������Ϣ
���岽��ѭ����ȡ������������packet��д�뱾��
���������رս������ͷ��ڴ�
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
    * @brief ����ص�����
    */
    static void* camera_call_back(void* data, void** p_pixels);

public:
private:
    IpcCameraPrivate* private_ptr_ = nullptr;  ///< ˽�����ݽṹ
};
