/********************************************************************************
** Form generated from reading UI file 'VideoDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEODIALOG_H
#define UI_VIDEODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <cmplayer.h>

QT_BEGIN_NAMESPACE

class Ui_VideoDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    CmPlayer *widget;

    void setupUi(QDialog *VideoDialog)
    {
        if (VideoDialog->objectName().isEmpty())
            VideoDialog->setObjectName(QStringLiteral("VideoDialog"));
        VideoDialog->resize(839, 599);
        gridLayout = new QGridLayout(VideoDialog);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(VideoDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(VideoDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(VideoDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(VideoDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        widget = new CmPlayer(VideoDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 550));

        gridLayout->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(VideoDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), VideoDialog, SLOT(open_local_file()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), VideoDialog, SLOT(play_video()));

        QMetaObject::connectSlotsByName(VideoDialog);
    } // setupUi

    void retranslateUi(QDialog *VideoDialog)
    {
        VideoDialog->setWindowTitle(QApplication::translate("VideoDialog", "VideoDialog", Q_NULLPTR));
        label->setText(QApplication::translate("VideoDialog", "TextLabel", Q_NULLPTR));
        lineEdit->setText(QString());
        pushButton->setText(QApplication::translate("VideoDialog", "\346\211\223\345\274\200\346\234\254\345\234\260\346\226\207\344\273\266", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("VideoDialog", "\346\222\255\346\224\276\350\247\206\351\242\221", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VideoDialog: public Ui_VideoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEODIALOG_H
