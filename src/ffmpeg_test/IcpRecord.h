#pragma once
extern "C" {
#include "libavformat/avformat.h"
#include "libavfilter/avfilter.h"
#include "libavutil/time.h"
}

#include "RecordInterface.h"
#include <memory>
#include <string>
#include "QString"
#include "CommonFuncs.h"

class IcpRecord : public RecordInterface {
    SINGLETON(IcpRecord)
public:
    IcpRecord();
    ~IcpRecord();


    virtual int device_check();


    virtual void start(QString file_name);


    virtual void stop();

    QVector<int> get_orig_img_size();

    void set_input_url(QString url);

private:
    void Init();
    std::shared_ptr<AVPacket> ReadPacketFromSource();
    void av_packet_rescale_ts(AVPacket* pkt, AVRational src_tb, AVRational dst_tb);
    int WritePacket(std::shared_ptr<AVPacket> packet);
    int OpenOutput(std::string outUrl);
    void CloseInput();
    void CloseOutput();
    static int interrupt_cb(void* ctx);

    int OpenInput();
    void video_thread();



private:
    std::string inputUrl;
    AVFormatContext* inputContext = nullptr;
    AVFormatContext* outputContext;

    int     device_type_    = 0;
    bool    is_started_     = false;            //是否已经开始
    int     option_         = 0;                    //动作标识
    bool    is_open_ = false;

    int img_width_  = 0;
    int img_height_ = 0;

};
