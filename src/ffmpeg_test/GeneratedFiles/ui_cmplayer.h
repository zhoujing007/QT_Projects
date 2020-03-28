/********************************************************************************
** Form generated from reading UI file 'cmplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMPLAYER_H
#define UI_CMPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <VLCQtWidgets/WidgetSeek.h>
#include <VLCQtWidgets/WidgetVideo.h>
#include <VLCQtWidgets/WidgetVolumeSlider.h>

QT_BEGIN_NAMESPACE

class Ui_cmplayer_form
{
public:
    QVBoxLayout *verticalLayout;
    VlcWidgetVideo *cmplayer_widget;
    QWidget *control_bar;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    VlcWidgetSeek *progress_bar;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *voice;
    VlcWidgetVolumeSlider *voice_slider;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *last;
    QPushButton *fast_back;
    QPushButton *play;
    QPushButton *fast_forward;
    QPushButton *next;
    QSpacerItem *horizontalSpacer;
    QPushButton *full;

    void setupUi(QWidget *cmplayer_form)
    {
        if (cmplayer_form->objectName().isEmpty())
            cmplayer_form->setObjectName(QStringLiteral("cmplayer_form"));
        cmplayer_form->resize(961, 909);
        cmplayer_form->setStyleSheet(QLatin1String("QWidget{background-color: rgb(0, 0, 0);}\n"
"QPushButton\n"
"{\n"
"	border: none;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgba(33, 62, 255, 125);\n"
"}\n"
"\n"
"QSlider::groove:horizontal {\n"
"border: 1px solid #4A708B;\n"
"background:transparent;\n"
"height: 5px;\n"
"border-radius: 3px;\n"
"padding-left:-1px;\n"
"padding-right:-1px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background: #575757;\n"
"border: 0px solid #777;\n"
"height: 10px;\n"
"border-radius: 2px;\n"
"}\n"
"QSlider::handle:horizontal \n"
"{\n"
"    background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, \n"
"    stop:0.6 #45ADED, stop:0.778409 rgba(255, 255, 255, 255));\n"
"\n"
"    width: 11px;\n"
"    margin-top: -3px;\n"
"    margin-bottom: -3px;\n"
"    border-radius: 5px;\n"
"}\n"
"QSlider::handle:horizontal:hover {\n"
"    background: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0.6 #2A8BDA, \n"
"    stop:0.778409 rgba(255, 255, 255, 255));\n"
"\n"
"   "
                        " width: 11px;\n"
"    margin-top: -3px;\n"
"    margin-bottom: -3px;\n"
"    border-radius: 5px;\n"
"}\n"
"QSlider::sub-page:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:0, y2:1, \n"
"    stop:0 #B1B1B1, stop:1 #c4c4c4);\n"
"background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,\n"
"    stop: 0 #5DCCFF, stop: 1 #1874CD);\n"
"border-radius: 3px;\n"
"}\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: #00009C;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"background: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(cmplayer_form);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        cmplayer_widget = new VlcWidgetVideo(cmplayer_form);
        cmplayer_widget->setObjectName(QStringLiteral("cmplayer_widget"));

        verticalLayout->addWidget(cmplayer_widget);

        control_bar = new QWidget(cmplayer_form);
        control_bar->setObjectName(QStringLiteral("control_bar"));
        control_bar->setMinimumSize(QSize(0, 85));
        control_bar->setMaximumSize(QSize(16777215, 85));
        control_bar->setStyleSheet(QLatin1String("\n"
"\n"
"QPushButton{\n"
"background-color: transparent;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgba(193, 193, 193, 60);\n"
"}\n"
"\n"
"QLabel{\n"
"background-color:transparent;\n"
"color:white;\n"
"}\n"
""));
        verticalLayout_2 = new QVBoxLayout(control_bar);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(5, -1, 5, -1);
        progress_bar = new VlcWidgetSeek(control_bar);
        progress_bar->setObjectName(QStringLiteral("progress_bar"));
        progress_bar->setMinimumSize(QSize(0, 40));
        progress_bar->setMaximumSize(QSize(16777215, 40));
        progress_bar->setStyleSheet(QLatin1String("\n"
"background-color: transparent;"));

        horizontalLayout_3->addWidget(progress_bar);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, -1, 10, 5);
        voice = new QPushButton(control_bar);
        voice->setObjectName(QStringLiteral("voice"));
        voice->setMinimumSize(QSize(32, 32));
        voice->setMaximumSize(QSize(32, 32));
        QIcon icon;
        icon.addFile(QStringLiteral("../PortableDetector/Resources/icons/voice.png"), QSize(), QIcon::Normal, QIcon::Off);
        voice->setIcon(icon);
        voice->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(voice);

        voice_slider = new VlcWidgetVolumeSlider(control_bar);
        voice_slider->setObjectName(QStringLiteral("voice_slider"));
        voice_slider->setMinimumSize(QSize(100, 0));
        voice_slider->setMaximumSize(QSize(100, 16777215));
        voice_slider->setStyleSheet(QStringLiteral(""));
        voice_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(voice_slider);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, -1, -1);
        last = new QPushButton(control_bar);
        last->setObjectName(QStringLiteral("last"));
        last->setMinimumSize(QSize(32, 32));
        last->setMaximumSize(QSize(32, 32));
        last->setStyleSheet(QLatin1String("QPushButton:hover{\n"
"icon: url(:/focus/Resources/icons/focus/last.png);\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../PortableDetector/Resources/icons/last.png"), QSize(), QIcon::Normal, QIcon::Off);
        last->setIcon(icon1);
        last->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(last);

        fast_back = new QPushButton(control_bar);
        fast_back->setObjectName(QStringLiteral("fast_back"));
        fast_back->setMinimumSize(QSize(32, 32));
        fast_back->setMaximumSize(QSize(32, 32));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../PortableDetector/Resources/icons/fast_back.png"), QSize(), QIcon::Normal, QIcon::Off);
        fast_back->setIcon(icon2);
        fast_back->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(fast_back);

        play = new QPushButton(control_bar);
        play->setObjectName(QStringLiteral("play"));
        play->setMinimumSize(QSize(32, 32));
        play->setMaximumSize(QSize(32, 32));
        play->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../PortableDetector/Resources/icons/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        play->setIcon(icon3);
        play->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(play);

        fast_forward = new QPushButton(control_bar);
        fast_forward->setObjectName(QStringLiteral("fast_forward"));
        fast_forward->setMinimumSize(QSize(32, 32));
        fast_forward->setMaximumSize(QSize(32, 32));
        QIcon icon4;
        icon4.addFile(QStringLiteral("../PortableDetector/Resources/icons/fast_forward.png"), QSize(), QIcon::Normal, QIcon::Off);
        fast_forward->setIcon(icon4);
        fast_forward->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(fast_forward);

        next = new QPushButton(control_bar);
        next->setObjectName(QStringLiteral("next"));
        next->setMinimumSize(QSize(32, 32));
        next->setMaximumSize(QSize(32, 32));
        QIcon icon5;
        icon5.addFile(QStringLiteral("../PortableDetector/Resources/icons/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        next->setIcon(icon5);
        next->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(next);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        full = new QPushButton(control_bar);
        full->setObjectName(QStringLiteral("full"));
        full->setMinimumSize(QSize(32, 32));
        full->setMaximumSize(QSize(32, 32));
        QIcon icon6;
        icon6.addFile(QStringLiteral("../PortableDetector/Resources/icons/full.png"), QSize(), QIcon::Normal, QIcon::Off);
        full->setIcon(icon6);
        full->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(full);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(control_bar);


        retranslateUi(cmplayer_form);

        QMetaObject::connectSlotsByName(cmplayer_form);
    } // setupUi

    void retranslateUi(QWidget *cmplayer_form)
    {
        cmplayer_form->setWindowTitle(QApplication::translate("cmplayer_form", "Form", Q_NULLPTR));
        voice->setText(QString());
        last->setText(QString());
        fast_back->setText(QString());
        play->setText(QString());
        fast_forward->setText(QString());
        next->setText(QString());
        full->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class cmplayer_form: public Ui_cmplayer_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMPLAYER_H
