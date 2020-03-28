#include "ffmpeg_test.h"
#include "CameraInterface.h"
#include "RecordInterface.h"
#include "VideoDialog.h"

ffmpeg_test::ffmpeg_test(QWidget* parent)
    : QMainWindow(parent) {
    ui.setupUi(this);
    display_thread_ = new DisplayThread(this);
    connect(display_thread_, SIGNAL(show_image(const QPixmap&)), this, SLOT(show_image(const QPixmap&)));
}

#define FreeThread(thread)\
    thread->wait(2000);

ffmpeg_test::~ffmpeg_test() {
    slot_close_camera();
}
void ffmpeg_test::start_record() {
    H264_SetUrl(ui.lineEdit->text());
    int ret = H264_Check();
    if (!ret) {
        LogInfo("未检测到录像设备");
    }

    if (cur_order_video_state_ == 0) {
        record_name_ = ui.lineEdit_2->text();
        cur_order_video_state_ = 1;
    }
}

void ffmpeg_test::close_record() {
    cur_order_video_state_ = 0;
    H264_Stop();
}

void ffmpeg_test::slot_open_camera() {
    QSize sz = ui.label_image->size();
    display_thread_->set_image_size(sz);
    display_thread_->thread_stop_ = false;
    display_thread_->show_over_ = true;

    QString error_str;
    display_thread_->start(QThread::NormalPriority);
    //打开相机
    if (!open_camera(error_str)) {
        LogInfo("相机打开失败") ;
    }

}

bool ffmpeg_test::open_camera(QString& error_str) {
    cur_index = ui.comboBox->currentIndex();
    CameraInterface* camera;
    if (!cur_index) {
        camera = CameraInterface::get_camera(TypeIpcCamera);
        camera->set_ipcurl(ui.lineEdit->text());
    } else {
        camera = CameraInterface::get_camera(TypeUVCcamera);
        if (cur_index == 1) {
            camera->is_use_C920_ = false;
        } else {
            camera->is_use_C920_ = true;
        }
    }
    //CameraInterface* camera = CameraInterface::get_camera(TypeIpcCamera);

    bool flag = camera->open();
    if (!flag) {
        LogInfo("相机打开失败");
        return false;
    }
    if (!camera->start_collection()) {
        error_str = "相机打开失败";
        LogError(error_str.toUtf8().data());
        LogError(camera->last_error().toUtf8().data());
        return false;
    }

    auto func = std::bind(&ffmpeg_test::camera_data, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    camera->set_out_callback(func);
    return true;
}

int call_back_count = 0;
void ffmpeg_test::camera_data(uchar* data, const int& width, const int& height) {
    call_back_count++;
    if (display_thread_->show_over_ && call_back_count % 2 == 0) {
        display_thread_->set_data(data);
        display_thread_->show_over_ = false;
    }
    if (cur_order_video_state_ == 1) {
        H264_Start(record_name_);
        cur_order_video_state_ = 2;
    }
}

void ffmpeg_test::show_image(const QPixmap& pix) {
    ui.label_image->setPixmap(pix);
}

void ffmpeg_test::slot_close_camera() {
    CameraInterface* camera;
    if (!cur_index) {
        CameraInterface::get_camera(TypeIpcCamera)->close();
    } else {
        CameraInterface::get_camera(TypeUVCcamera)->close();
    }
    display_thread_->thread_stop_ = true;
    FreeThread(display_thread_);
}

void ffmpeg_test::vedio_player() {
    VideoDialog video_widget_;
    video_widget_.exec();
}
