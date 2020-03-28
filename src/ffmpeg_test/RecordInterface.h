#pragma once
#include <string>
#include <thread>
#include "QString"

enum RecordType {
    TypeUsbRecord,
    TypeIpcRecord
};
class RecordInterface {
public:
    RecordInterface() {};
    ~RecordInterface() {};
    virtual int device_check() = 0;
    virtual void start(QString file_name) = 0;
    virtual void stop() = 0;
    virtual void set_input_url(QString camera_url) = 0;

    std::thread thread_;

    static RecordInterface* get_record();

private:

};



#define  H264_Check() RecordInterface::get_record()->device_check()
#define  H264_Start(file_name) RecordInterface::get_record()->start(file_name)
#define  H264_Stop() RecordInterface::get_record()->stop()
#define  H264_SetUrl(camera_url) RecordInterface::get_record()->set_input_url(camera_url)
