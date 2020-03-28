#include "media_player_test.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <QAudioDeviceInfo>
#include <QAudioInputSelectorControl>
#include "MusicPlayer.h"
#include <QMediaService>
#include <QDebug>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QMediaPlayer* player = new QMediaPlayer();
    QList<QAudioDeviceInfo> devices = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);
    for (auto dev : devices) {
        std::cout << dev.deviceName().toLocal8Bit().data();
    }
    //     QString name = devices.front().deviceName();
    //     qDebug() << name;
    QString defual_name = QAudioDeviceInfo::defaultInputDevice().deviceName();
    QMediaService* svc = player->service();
    if (svc != nullptr) {
        QAudioInputSelectorControl* in = qobject_cast<QAudioInputSelectorControl*>
                                         (svc->requestControl(QAudioInputSelectorControl_iid));
        if (in != nullptr) {
            in->setActiveInput("Á¢ÌåÉù»ìÒô(2 - Realtek High Definition Audio)");
            svc->releaseControl(in);
        }
    }
    MusicPlayer mp;
    mp.set_media(QStringList() << "low_warn.wav" << "high_warn.wav");
    mp.wait_for_play();
    int intput = 0;
    do {
        std::cout << "intput 0 or 1 , other will quit";
        std::cin >> intput;
        if (intput == 1 || intput == 0) {
            mp.play((MusicPlayer::WarnLevel)intput);
        } else {
            intput = -1;
        }
    } while (intput != -1);



    //  media_player_test w;
    //  w.show();
    return a.exec();
}
