#include "IpcCamera.h"
#include "vlc/vlc.h"
#include <opencv2/opencv.hpp>
#include <windows.h>


extern "C" {
#include "libavformat/avformat.h"
#include "libavfilter/avfilter.h"
}

class IpcCameraPrivate {
    std::thread             read_thread_;
    bool                    exit_ = true;
    bool                    collection_ = false;
    cv::Mat                 IPC_videobuf;
    libvlc_instance_t*      ipc_inst;
    libvlc_media_player_t*  ipc_mp;
    libvlc_media_t*         ipc_m;
    std::string             rtspurl = "rtsp://admin:admin000@192.168.0.220:554/cam/realmonitor?channel=1&subtype=2";
    std::mutex              mutex_;
    cv::Mat                 current_frame_;
    cv::Mat                 raw_frame_;
    IplImage*               raw_IPC_img;
    unsigned char* m_pBufferRGB;                ///< RGB图像数据，用于显示和保存bmp图像
    friend class IpcCamera;
};

IpcCamera* g_ipc_camera = nullptr;
IpcCamera::IpcCamera() {
    private_ptr_ = new IpcCameraPrivate();
    g_ipc_camera = this;
}

IpcCamera::~IpcCamera() {
}


int frame_width = 0;
int frame_height = 0;
bool IpcCamera::open() {
    image_width_ = 1292;
    image_height_ = 964;

    int frame_width = 1280;
    int frame_height = 720;
    av_register_all();
    avformat_network_init();
    avfilter_register_all();

    AVDictionary* opts = NULL;
    av_dict_set(&opts, "stimeout", "3000000", 0);
    AVFormatContext* inputContext = avformat_alloc_context();
    int ret = avformat_open_input(&inputContext, private_ptr_->rtspurl.c_str(), nullptr, &opts);


    if (inputContext != nullptr) {
        avformat_close_input(&inputContext);
    }

    if (ret < 0) {
        return false;
    }

    private_ptr_->IPC_videobuf.create(frame_height, frame_width, CV_8UC3);// IPC采集的BUF

    private_ptr_->ipc_inst = libvlc_new(0, NULL);
    if (private_ptr_->ipc_inst == NULL) {
        printf("VLC初始化失败");
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return false;
    }
    //设置IPC的URL
    private_ptr_->ipc_m = libvlc_media_new_location(private_ptr_->ipc_inst, private_ptr_->rtspurl.c_str());

    //优化网络参数，减少图像花屏
    libvlc_media_add_option(private_ptr_->ipc_m, "--network-caching=1000");  //网络额外缓存值 (ms)
    libvlc_media_add_option(private_ptr_->ipc_m, "--rtsp-frame-buffer-size=1000000");   //RTSP帧缓冲大小，默认大小为100000
    libvlc_media_add_option(private_ptr_->ipc_m, "--rtsp-tcp");   //RTSP采用TCP传输方式


    //libvlc_media_add_option(ipc_m, ":sout=#duplicate{dst=std{access=file,mux=avi,dst=f:\\test2018.mp4},dst=display}");
    private_ptr_->ipc_mp = libvlc_media_player_new_from_media(private_ptr_->ipc_m);


    //设置回调采集
    libvlc_video_set_callbacks(private_ptr_->ipc_mp, camera_call_back, NULL, NULL, NULL);
    //设置采集格式
    libvlc_video_set_format(private_ptr_->ipc_mp, "RV24", frame_width, frame_height, frame_width * 3);
    libvlc_media_release(private_ptr_->ipc_m);



    if (!private_ptr_) {
        return false;
    }
    private_ptr_->exit_ = false;
    private_ptr_->collection_ = false;
    return true;

}

bool IpcCamera::start_collection() {
    if (!private_ptr_) {
        return false;
    }


    //启动采集
    for (int i = 0; i < 10; i++) {
        int ret = libvlc_media_player_play(private_ptr_->ipc_mp);
        printf("%d", ret);
    }
    private_ptr_->collection_ = true;
    return true;

}

bool IpcCamera::stop_collection() {
    if (!private_ptr_) {
        return true;
    }
    private_ptr_->collection_ = false;
    return true;
}

QString IpcCamera::last_error() {
    return "";
}

void IpcCamera::close() {
    if (!private_ptr_) {
        return;
    }
    private_ptr_->collection_ = false;
    private_ptr_->exit_ = true;
    if (private_ptr_->ipc_mp != NULL) {
        libvlc_media_player_stop(private_ptr_->ipc_mp);
        // Free the media_player
        libvlc_media_player_release(private_ptr_->ipc_mp);
        libvlc_release(private_ptr_->ipc_inst);
        private_ptr_->ipc_mp = NULL;
        private_ptr_->ipc_inst = NULL;
    }

    return;
}

void IpcCamera::set_out_callback(callback_func func) {
    out_callback_ = func;
}

void IpcCamera::set_ipcurl(QString ipcurl) {
    this->private_ptr_->rtspurl = ipcurl.toStdString();
}

void* IpcCamera::camera_call_back(void* data, void** p_pixels) {
    if (!g_ipc_camera->private_ptr_->collection_ || g_ipc_camera->private_ptr_->exit_) {
        return nullptr;
    }

    *p_pixels = g_ipc_camera->private_ptr_->IPC_videobuf.data;  //图像采集

    g_ipc_camera->private_ptr_->raw_IPC_img = &IplImage(g_ipc_camera->private_ptr_->IPC_videobuf);

    //cvCvtColor(g_ipc_camera->private_ptr_->raw_IPC_img, g_ipc_camera->private_ptr_->raw_IPC_img, cv::COLOR_BGR2RGB);
    g_ipc_camera->private_ptr_->m_pBufferRGB = (unsigned char*)(g_ipc_camera->private_ptr_->raw_IPC_img->imageData);
    cv::Mat srcMat(720, 1280, CV_8UC3, cv::Scalar(0, 0, 0));
    memcpy(srcMat.data, g_ipc_camera->private_ptr_->m_pBufferRGB, 720 * 1280 * 3);

    cv::resize(srcMat, g_ipc_camera->private_ptr_->current_frame_, cv::Size(g_ipc_camera->image_width_, g_ipc_camera->image_height_));
    flip(g_ipc_camera->private_ptr_->current_frame_, g_ipc_camera->private_ptr_->current_frame_, 0);
    //cvFlip(g_ipc_camera->private_ptr_->raw_IPC_img, g_ipc_camera->private_ptr_->raw_IPC_img);

    g_ipc_camera->private_ptr_->mutex_.lock();
    g_ipc_camera->private_ptr_->raw_frame_ = g_ipc_camera->private_ptr_->current_frame_.clone();
    g_ipc_camera->private_ptr_->mutex_.unlock();

    if (g_ipc_camera->out_callback_) {
        g_ipc_camera->out_callback_((unsigned char*)g_ipc_camera->private_ptr_->current_frame_.data, g_ipc_camera->image_width_, g_ipc_camera->image_height_);
    }
    return nullptr;
}

