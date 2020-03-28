#include "IcpRecord.h"
#include <iostream>

static int64_t lastReadPacktTime = 0;

IcpRecord::IcpRecord() {};
IcpRecord::~IcpRecord() {
};


void IcpRecord::Init() {
    av_register_all();
    avfilter_register_all();
    avformat_network_init();
    av_log_set_level(AV_LOG_ERROR);
}



std::shared_ptr<AVPacket> IcpRecord::ReadPacketFromSource() {
    std::shared_ptr<AVPacket> packet(static_cast<AVPacket*>(av_malloc(sizeof(AVPacket))), [&](AVPacket * p) {
        av_packet_free(&p);
        av_freep(&p);
    });
    av_init_packet(packet.get());
    lastReadPacktTime = av_gettime();
    int ret = av_read_frame(inputContext, packet.get());
    if (ret >= 0) {
        return packet;
    } else {
        return nullptr;
    }
}
void IcpRecord::av_packet_rescale_ts(AVPacket* pkt, AVRational src_tb, AVRational dst_tb) {
    if (pkt->pts != AV_NOPTS_VALUE)
        pkt->pts = av_rescale_q(pkt->pts, src_tb, dst_tb);
    if (pkt->dts != AV_NOPTS_VALUE)
        pkt->dts = av_rescale_q(pkt->dts, src_tb, dst_tb);
    if (pkt->duration > 0)
        pkt->duration = av_rescale_q(pkt->duration, src_tb, dst_tb);
}
int IcpRecord::WritePacket(std::shared_ptr<AVPacket> packet) {
    auto inputStream = inputContext->streams[packet->stream_index];
    auto outputStream = outputContext->streams[packet->stream_index];
    av_packet_rescale_ts(packet.get(), inputStream->time_base, outputStream->time_base);
    return av_interleaved_write_frame(outputContext, packet.get());
}

int IcpRecord::OpenOutput(std::string outUrl) {

    int ret = avformat_alloc_output_context2(&outputContext, nullptr, "mpegts", outUrl.c_str());
    if (ret < 0) {
        av_log(NULL, AV_LOG_ERROR, "open output context failed\n");
        goto Error;
    }

    ret = avio_open2(&outputContext->pb, outUrl.c_str(), AVIO_FLAG_WRITE, nullptr, nullptr);
    if (ret < 0) {
        av_log(NULL, AV_LOG_ERROR, "open avio failed");
        goto Error;
    }

    for (int i = 0; i < inputContext->nb_streams; i++) {
        AVStream* stream = avformat_new_stream(outputContext, inputContext->streams[i]->codec->codec);
        ret = avcodec_copy_context(stream->codec, inputContext->streams[i]->codec);
        if (ret < 0) {
            av_log(NULL, AV_LOG_ERROR, "copy coddec context failed");
            goto Error;
        }
    }

    ret = avformat_write_header(outputContext, nullptr);
    if (ret < 0) {
        av_log(NULL, AV_LOG_ERROR, "format write header failed");
        goto Error;
    }

    av_log(NULL, AV_LOG_FATAL, " Open output file success %s\n", outUrl.c_str());
    return ret;
Error:
    if (outputContext) {
        for (int i = 0; i < outputContext->nb_streams; i++) {
            avcodec_close(outputContext->streams[i]->codec);
        }
        avformat_close_input(&outputContext);
    }
    return ret;
}

void IcpRecord::CloseInput() {
    if (inputContext != nullptr) {
        avformat_close_input(&inputContext);
    }
}

void IcpRecord::CloseOutput() {
    if (outputContext != nullptr) {
        for (int i = 0; i < outputContext->nb_streams; i++) {
            AVCodecContext* codecContext = outputContext->streams[i]->codec;
            avcodec_close(codecContext);
        }
        avformat_close_input(&outputContext);
    }
}
int IcpRecord::interrupt_cb(void* ctx) {
    int  timeout = 3;
    if (av_gettime() - lastReadPacktTime > timeout * 1000 * 1000) {
        return -1;
    }
    return 0;
}

int IcpRecord::OpenInput() {

    inputContext = avformat_alloc_context();
    lastReadPacktTime = av_gettime();
    inputContext->interrupt_callback.callback = interrupt_cb;
    int ret = avformat_open_input(&inputContext, inputUrl.c_str(), nullptr, nullptr);
    if (ret < 0) {
        av_log(NULL, AV_LOG_ERROR, "Input file open input failed\n");
        return  ret;
    }
    return ret;
}

void IcpRecord::video_thread() {
    bool isfirstKey = false;
    while (1) {
        if (option_ == 2) {
            break;
        }
        auto packet = ReadPacketFromSource();
        if (packet) {
            //ÊÇ·ñÊÇ¹Ø¼üÖ¡
            if (packet->flags & AV_PKT_FLAG_KEY) {
                isfirstKey = true;
            }
            if (isfirstKey) {
                int ret = WritePacket(packet);
                if (ret < 0) {
                    LogInfo("WritePacket failed!");
                }
            }
        } else {
            break;
        }
    }
}
int IcpRecord::device_check() {
    Init();
    device_type_ = OpenInput() < 0 ? 0 : 1;
    //     if (device_type_ == 2) {
    //         is_open_ = true;
    //     }
    return device_type_;
}

void IcpRecord::start(QString file_name) {
    if (!is_open_) {
        OpenInput();
        int ret = avformat_find_stream_info(inputContext, nullptr);
        if (ret < 0) {
            av_log(NULL, AV_LOG_ERROR, "Find input file stream inform failed\n");
        } else {
            av_log(NULL, AV_LOG_FATAL, "Open input file  %s success\n", inputUrl.c_str());
        }
        is_open_ = true;
    }
    OpenOutput(file_name.toStdString());
    if (device_type_ == 0) {
        return;
    }
    if (!is_started_) {
        is_started_ = true;
        option_ = 1;
        auto func = std::bind(&IcpRecord::video_thread, this);
        thread_ = std::thread(func);
    }
}

void IcpRecord::stop() {
    if (is_started_) {
        is_started_ = false;
        option_ = 2;
        // single_loader_ptr->DLL_H264_stop();
        if (thread_.joinable()) {
            thread_.join();
        }
        if (is_open_) {
            CloseInput();
            is_open_ = false;
        }
        CloseOutput();

    }
}

QVector<int> IcpRecord::get_orig_img_size() {
    QVector<int> img_size;
    if (outputContext != nullptr) {
        if (outputContext->nb_streams > 1) {
            img_size.append(outputContext->streams[0]->codec->width);
            img_size.append(outputContext->streams[0]->codec->height);
        }
    }
    return img_size;
}

void IcpRecord::set_input_url(QString url) {
    inputUrl = url.toStdString();
}

