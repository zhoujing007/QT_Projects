#ifndef FFMPEG_TEST_H
#define FFMPEG_TEST_H

#include <QtWidgets/QMainWindow>
#include "ui_ffmpeg_test.h"
#include <thread>
#include <QThread>
#include "DisplayThread.h"

class ffmpeg_test : public QMainWindow {
    Q_OBJECT

public:
    ffmpeg_test(QWidget* parent = 0);
    ~ffmpeg_test();

private:
    Ui::ffmpeg_testClass ui;

    DisplayThread*               display_thread_ = nullptr;

    int   cur_order_video_state_ = 0;//0 未开始  1，开始  2， 录像中
    bool open_camera(QString& error_str);

    QString record_name_;
    int cur_index;
private slots:
    void start_record();
    void close_record();
    void slot_open_camera();
    void slot_close_camera();
    void vedio_player();

    void camera_data(uchar* data, const int& width, const int& height);
    void show_image(const QPixmap& pix);
};

#endif // FFMPEG_TEST_H
