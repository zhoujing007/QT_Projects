#include "CmPlayer.h"
#include <QFileDialog>
#include <QInputDialog>

#include <VLCQtCore/Common.h>
#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>
#include <QDebug>
#include <QMouseEvent>

CmPlayer::CmPlayer(QWidget* parent)
    : QWidget(parent),
      _media(0) {
    ui.setupUi(this);
    ui.voice->setIcon(QIcon("Resources/icons/voice.png"));
    ui.last->setIcon(QIcon("Resources/icons/last.png"));
    ui.fast_back->setIcon(QIcon("Resources/icons/fast_back.png"));
    ui.play->setIcon(QIcon("Resources/icons/play.png"));
    ui.fast_forward->setIcon(QIcon("Resources/icons/fast_forward.png"));
    ui.next->setIcon(QIcon("Resources/icons/next.png"));
    ui.full->setIcon(QIcon("Resources/icons/full.png"));

    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    ui.voice_slider->installEventFilter(this);
    ui.voice_slider->setMaximum(200);
    ui.voice_slider->hide();
    _instance = new VlcInstance(VlcCommon::args(), this);
    _player = new VlcMediaPlayer(_instance);
    _player->setVideoWidget(ui.cmplayer_widget);

    ui.cmplayer_widget->setMediaPlayer(_player);
    ui.voice_slider->setMediaPlayer(_player);
    ui.voice_slider->setVolume(100);
    ui.progress_bar->setMediaPlayer(_player);

    //connect(ui.fast_back, &QPushButton::clicked, this, &CmPlayer::openLocal);
    //connect(ui.fast_forward, &QPushButton::clicked, this, &CmPlayer::openUrl);
    connect(ui.play, &QPushButton::clicked, this, &CmPlayer::play_img_change);
    //connect(ui.play, &QPushButton::clicked, _player, &VlcMediaPlayer::togglePause);

    //点击隐藏显示音量区
    connect(ui.voice, &QPushButton::clicked, this, &CmPlayer::on_pushButton_volume_clicked);
    connect(ui.voice_slider, SIGNAL(valueChanged(int)), this, SLOT(slider_volume_changed(int)));
    connect(ui.full, &QPushButton::clicked, this, &CmPlayer::control_clicked);

    //初始化定时器
    duration_call_back_ = new QTimer(this);
    connect(duration_call_back_, &QTimer::timeout, this, &CmPlayer::play_call_back);

    play_state_timer_ = new QTimer(this);
    connect(play_state_timer_, SIGNAL(timeout()), this, SLOT(state_check()));
    play_state_timer_->start(20);
}


CmPlayer::~CmPlayer() {
    delete _player;
    delete _media;
    delete _instance;
    duration_call_back_->stop();
    play_state_timer_->stop();
    delete duration_call_back_;
    delete play_state_timer_;
}

WId CmPlayer::request() {
    return this->winId();
}

void CmPlayer::release() {

}

void CmPlayer::set_url(QString url) {
    if (url.isEmpty())
        return;
    _media = new VlcMedia(url, true, _instance);
    is_set_url_ = true;
    connect(_player, SIGNAL(stateChanged()), this, SLOT(play_state_change()));
    _player->open(_media);
}

void CmPlayer::play_state_change() {
    //记录视频长度
    all_time_length = _player->length();
    Vlc::State cur_play_state = _player->state();
    if (cur_play_state == Vlc::Playing) {
        ui.play->setIcon(QIcon("Resources/icons/pause.png"));
    } else {
        ui.play->setIcon(QIcon("Resources/icons/play.png"));
    }
    if (is_first_play_ && all_time_length > 1e-3) {
        if (first_duration_ > 1e-3) {
            double cur_location = first_duration_ * 1000 / all_time_length;
            _player->setPosition(cur_location);
        }
        is_first_play_ = false;
    }
}

void CmPlayer::play_pause() {
    Vlc::State cur_play_state = _player->state();
    if (cur_play_state == Vlc::Playing) {
        _player->pause();
    }
}

void CmPlayer::play(double from_duration /*= 0.0*/) {
    if (!is_set_url_) {
        emit video_start_play();
        is_first_play_ = true;
        first_duration_ = from_duration;
    } else {
        _player->play();
        if (from_duration > 1e-3 && all_time_length > 1e-3) {
            double cur_location = from_duration * 1000 / all_time_length;
            _player->setPosition(cur_location);
        }
    }
}

void CmPlayer::set_position(double pos) {
    //用于暂停下移动视频位置，播放中可以使用play函数
    _player->play();
    //设置位置
    _player->setPosition(pos);
    //暂停视频
    _player->pause();
}

void CmPlayer::play_img_change() {
    Vlc::State cur_play_state = _player->state();
    if (cur_play_state == Vlc::Playing) {
        _player->pause();
    } else {
        if (!is_set_url_) {
            emit video_start_play();
        } else {
            _player->play();
        }
    }
}


void CmPlayer::control_clicked() {
    if (control_size_normal) {
        parent_ = dynamic_cast<QWidget*>(this->parent());
        QWidget* root = parent_;
        QWidget* temp = nullptr;
        do {
            temp = dynamic_cast<QWidget*>(root->parent());
            if (temp) {
                root = temp;
            }
        } while (temp != nullptr);

        //QWidget* aa = new QWidget(root);
        this->setParent(nullptr);
        ui.full->setIcon(QIcon("Resources/icons/mini.png"));
        this->showMaximized();
        this->show();

        root->setFixedSize(1, 1);

    } else {
        QWidget* root = parent_;
        QWidget* temp = nullptr;
        do {
            temp = dynamic_cast<QWidget*>(root->parent());
            if (temp) {
                root = temp;
            }
        } while (temp != nullptr);
        root->setFixedSize(1920, 1080);

        this->setParent(parent_);
        this->show();
        ui.full->setIcon(QIcon("Resources/icons/full.png"));

        emit sig_vediofromchange();
    }
    control_size_normal = !control_size_normal;
}

void CmPlayer::slider_volume_changed(int volume_value) {
    ui.voice_slider->setVolume(volume_value);
    if (volume_value == 0) {
        ui.voice->setIcon(QIcon("Resources/icons/mute.png"));
    } else {
        ui.voice->setIcon(QIcon("Resources/icons/voice.png"));
    }
}

void CmPlayer::play_call_back() {
    if (_player && is_set_url_) {
        double cur_location = _player->position();
        double cur_time_location = all_time_length / 1000.0f * cur_location;
        emit video_pos(cur_time_location);
    }
}

bool state_slider_volume = false;
void CmPlayer::on_pushButton_volume_clicked() {
    if (state_slider_volume) {
        ui.voice_slider->hide();
    } else {
        ui.voice_slider->setValue(ui.voice_slider->value());
        //计算位置，使其位于音量控制按钮的上方
        //ui.voice_slider->setGeometry(QRect(ui.voice->pos().rx(), this->height() - ui.control_bar->height() - 100, 30, 100));
        ui.voice_slider->show();
    }
    state_slider_volume = !state_slider_volume;
}


bool CmPlayer::eventFilter(QObject* obj, QEvent* event) {
    if (obj == ui.voice_slider) {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
        if ((event->type() == QEvent::MouseButtonPress && mouseEvent->button() == Qt::LeftButton) || event->type() == QEvent::MouseMove) {
            int dur = ui.voice_slider->maximum() - ui.voice_slider->minimum();
            int pos = ui.voice_slider->minimum() + dur * ((double)mouseEvent->x() / ui.voice_slider->width());
            if (pos != ui.voice_slider->sliderPosition()) {
                ui.voice_slider->setValue(pos);
            }
        }
    }
    return QWidget::eventFilter(obj, event);
}

void CmPlayer::closeEvent(QCloseEvent* event) {
    control_clicked();
    event->ignore();
}

void CmPlayer::state_check() {
    Vlc::State cur_play_state = _player->state();
    if (cur_play_state == Vlc::Playing) {
        if (!is_timer_start) {
            is_timer_start = true;
            duration_call_back_->start(33);
        }
    } else {
        if (_player->state() == Vlc::Ended) {
            _player->open(_media);
            QTimer::singleShot(200, this, [&]() {
                _player->pause();
            });
        }
        if (is_timer_start) {
            is_timer_start = false;
            duration_call_back_->stop();
        }
    }
}
void CmPlayer::openLocal() {
    QString file =
        QFileDialog::getOpenFileName(this, tr("Open file"),
                                     QDir::homePath(),
                                     tr("Multimedia files(*)"));

    if (file.isEmpty())
        return;

    _media = new VlcMedia(file, true, _instance);
    _player->open(_media);
    ui.play->setIcon(QIcon("Resources/icons/pause.png"));

}

void CmPlayer::openUrl() {
    QString url =
        QInputDialog::getText(this, tr("Open Url"), tr("Enter the URL you want to play"));

    if (url.isEmpty())
        return;

    _media = new VlcMedia(url, _instance);
    _player->open(_media);
    ui.play->setIcon(QIcon("Resources/icons/pause.png"));
}