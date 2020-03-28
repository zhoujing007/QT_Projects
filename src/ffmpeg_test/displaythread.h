
#ifndef DisplayThread_H
#define DisplayThread_H

#include <QThread>
#include <QSize>
#include <QPixmap>

const int   PICTURE_WIDTH = 1292;
const int   PICTURE_HEIGHT = 964;
/**@brief 内存录像帧数*/
const int   VIDEO_LONG = 275;

/**@brief 图像帧数据长度 =image_width*image_height*3*/
const int   FRAME_LONG = PICTURE_WIDTH * PICTURE_HEIGHT * 3;//3736464;

class DisplayThread  : public QThread {

    Q_OBJECT

public:
    DisplayThread(QObject* parent = nullptr);
    ~ DisplayThread();
    void set_data(uchar* data);

    void set_image_size(QSize size);

    bool show_over_ = true;
    bool show_flag_ = false;
    QSize image_size_;
    bool has_data_ = false;

    bool thread_stop_ = false;             ///< 线程退出标志
private:
    virtual void run();
    void format_rgb(uchar* rgb_data, int length);
    uchar data_[FRAME_LONG];
signals:
    void show_image(const QPixmap& pixmap);
};

#endif // DisplayThread_H
