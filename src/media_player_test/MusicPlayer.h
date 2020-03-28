#pragma once

#include <QMediaPlayer>
#include <thread>
#include "QEventLoop"
#include "QTimer"

class MusicPlayer {

public:
    enum WarnLevel {
        LOW_LEVEL_WARN,
        HIGH_LEVEL_WARN,
    };
    void wait_for_play() {
        stop_ = false;
        need_play_ = false;
        play_over_ = true;
        play_thread_ = std::thread(thread_play_func, this);
    }

    void set_media(QStringList file_list) {
        file_list_ = file_list;
        player_.setVolume(50);
    }

    void play(WarnLevel level) {
        QString cur_music = file_list_[level];
        player_.stop();
        player_.setMedia(QUrl::fromLocalFile(file_list_[level]));
        if (play_over_) {
            player_.setPosition(0);
            player_.stop();
            need_play_ = true;
        }
    }

    void stop() {
        stop_ = true;
        if (play_thread_.joinable()) {
            play_thread_.join();
        }
    }

private:
    static void thread_play_func(void* p_self) {
        MusicPlayer* self = (MusicPlayer*)p_self;
        while (!self->stop_) {
            if (self->need_play_ && self->play_over_) {
                self->raw_play();
            } else {
                std::this_thread::sleep_for(std::chrono::milliseconds(20));
            }
        }
    }
    void raw_play() {
        player_.play();
        QEventLoop loop;
        QTimer::singleShot(1000, [&]() {
            loop.quit();
            play_over_ = true;
            need_play_ = false;
        });
        loop.exec();
    }

private:
    bool            need_play_ = false;
    bool            play_over_ = true;
    QMediaPlayer    player_;
    std::thread     play_thread_;
    bool            stop_ = false;
    QStringList     file_list_;
};
// MusicPlayer::instance()->set_media("tada.wav");
// MusicPlayer::instance()->wait_for_play();
//MusicPlayer::instance()->play();
//MusicPlayer::instance()->stop();