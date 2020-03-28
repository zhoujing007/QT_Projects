#pragma once
#include <QtWidgets/QWidget>
#include "ui_cmplayer.h"
#include <VLCQtCore/VideoDelegate.h>
#include <QPushButton>
// namespace Ui {
// class cmplayer_form;
// }

class VlcInstance;
class VlcMedia;
class VlcMediaPlayer;
/*class EqualizerDialog;*/

class CmPlayer : public QWidget, VlcVideoDelegate {
    Q_OBJECT
public:
    explicit CmPlayer(QWidget* parent = 0);
    ~CmPlayer();

    virtual WId request();

    virtual  void release();

    /*
    * @brief:    set_url
    * @Parameter: QString url
    * @Returns:   void
    */
    void set_url(QString url);
    /*
    * @brief:    play
    * @Parameter: double from_duration
    * @Returns:   void
    */
    void play(double from_duration = 0.0);

    void set_position(double pos);

    void play_pause();
private slots:
    void openLocal();
    void openUrl();
    void play_img_change();
    void control_clicked();
    void slider_volume_changed(int volume_value);
    void play_call_back();
    void state_check();
    void on_pushButton_volume_clicked();
signals:
    void video_pos(double);
    void video_start_play();
    void sig_vediofromchange();
private slots:
    void play_state_change();
private:
    Ui::cmplayer_form ui;

    VlcInstance*    _instance;
    VlcMedia*       _media;
    VlcMediaPlayer* _player;

    QTimer*         duration_call_back_ = nullptr;      ///< 定时检测播放位置
    QTimer*         play_state_timer_ = nullptr;        ///< 监视播放状态定时器
    bool            is_timer_start = false;
    QWidget*        parent_;
    double          all_time_length = 0.0f;
    bool            is_set_url_ = false;                ///是否设置过url
    bool            is_first_play_ = false;             ///是否是第一次播放
    double          first_duration_ = 0.0f;             ///第一次播放位置
    bool control_size_normal = true;

    virtual bool eventFilter(QObject* obj, QEvent* e);
    virtual void closeEvent(QCloseEvent* event);
};

