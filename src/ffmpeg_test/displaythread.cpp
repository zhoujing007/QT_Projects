#include "DisplayThread.h"
#include "thread"
#include <QImage>
#include <QDebug>
#include "logger.h"

extern int call_back_count;

#pragma execution_character_set("utf-8")
DisplayThread::DisplayThread(QObject* parent)
    : QThread(parent) {
    memset(data_, 0, FRAME_LONG);
}
uchar test_data[FRAME_LONG] = { 0 };
bool test_test = false;
void DisplayThread::set_data(uchar* data) {
    if (!has_data_) {
        memcpy(data_, data, FRAME_LONG);
        has_data_ = true;
    }

}

void DisplayThread::set_image_size(QSize size) {
    image_size_ = size;
}

void DisplayThread::format_rgb(uchar* rgb_data, int length) {
    for (int i = 0; i < length; i += 3) {
        uchar temp = rgb_data[i];
        rgb_data[i] = rgb_data[i + 2];
        rgb_data[i + 2] = temp;
    }
}

void DisplayThread::run() {
    int width = PICTURE_WIDTH;
    int height = PICTURE_HEIGHT;
    long total = width * height * 3;

    while (!(thread_stop_)) {
        if (!(show_over_)) {
            if (has_data_) {
                format_rgb(data_, total);
                QImage image(data_, width, height, QImage::Format_RGB888);
                //                 QMatrix matrix;
                //                 matrix.rotate(90);
                //
                //                 clock_t start = clock();
                //                 image.transformed(matrix);
                //                 int msecs = clock() - start;
                //                 qDebug() << "rotate time = " << msecs;
                image = image.mirrored(false, true);
                image = image.scaled(image_size_);
                QPixmap pixmap = QPixmap::fromImage(image);

                emit show_image(pixmap);
                has_data_ = false;
                show_over_ = true;
            }
        } else {
            msleep(2);
        }
    }
}

DisplayThread::~DisplayThread() {

}

