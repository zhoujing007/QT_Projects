#pragma once


#include <QString>
#include "CommonFuncs.h"
#include <functional>

//�����ⲿ����ͼ�����ݵĺ���ָ��
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
    * @brief �����
    * @return true ��ʶ�򿪳ɹ���false ��ʾ��ʧ��
    * @note ����ʧ��ʱ���ɵ���last_error()��������ʧ����Ϣ�鿴
    */
    virtual bool open() = 0;

    /*
    * @brief ��ʼ�ɼ�����
    * @return true ��ʼ�ɼ��ɹ���false ��ʼ�ɼ�ʧ��
    * @note �ɼ�ʧ��ʱ���ɵ���last_error()��������ʧ����Ϣ�鿴
    */
    virtual bool start_collection() = 0;

    /*
    * @brief ֹͣ�ɼ�����
    * @return true ֹͣ�ɼ��ɹ���false ֹͣ�ɼ�ʧ��
    * @note ֹͣ�ɼ�ʧ��ʱ���ɵ���last_error()��������ʧ����Ϣ�鿴
    */
    virtual bool stop_collection() = 0;

    /*
    * @brief ������Ϣ��ȡ
    * @return QString ������Ϣ�ַ���
    */
    virtual QString last_error() = 0;

    /**@brief �ر����*/
    virtual void close() = 0;


    virtual void set_out_callback(callback_func func) = 0;

    virtual void set_ipcurl(QString camera_url) = 0;

    static CameraInterface* get_camera(CameraType camera_type);


public:
    callback_func      out_callback_ = nullptr;

    int64_t image_width_ = 1292;
    int64_t image_height_ = 964;
    int64_t             m_nContrast;                ///< �Աȶ�ֵ
    int64_t             m_nColorCorrection = 0;     ///< ��ɫУ��ֵ
    double              m_dGamma;                   ///< Gammmaֵ
    int                 m_nLutLength;               ///< ���ұ���
    unsigned char*      m_pGammaLut;                ///< Gamma���ұ�
    unsigned char*      m_pContrastLut;             ///< �ԱȶȲ��ұ�

    bool                is_use_C920_ = false;

private:

};
