/********************************************************************************
** Form generated from reading UI file 'ffmpeg_test.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FFMPEG_TEST_H
#define UI_FFMPEG_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ffmpeg_testClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_image;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ffmpeg_testClass)
    {
        if (ffmpeg_testClass->objectName().isEmpty())
            ffmpeg_testClass->setObjectName(QStringLiteral("ffmpeg_testClass"));
        ffmpeg_testClass->resize(953, 732);
        centralWidget = new QWidget(ffmpeg_testClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(300, 0));

        horizontalLayout->addWidget(lineEdit);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 7);

        label_image = new QLabel(centralWidget);
        label_image->setObjectName(QStringLiteral("label_image"));
        label_image->setMinimumSize(QSize(0, 600));

        gridLayout->addWidget(label_image, 1, 0, 1, 7);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(76, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 2, 2, 1, 1);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(124, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 6, 1, 1);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 2, 4, 1, 1);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 2, 5, 1, 1);

        ffmpeg_testClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ffmpeg_testClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 953, 23));
        ffmpeg_testClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ffmpeg_testClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ffmpeg_testClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ffmpeg_testClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ffmpeg_testClass->setStatusBar(statusBar);

        retranslateUi(ffmpeg_testClass);
        QObject::connect(pushButton, SIGNAL(clicked()), ffmpeg_testClass, SLOT(start_record()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), ffmpeg_testClass, SLOT(close_record()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), ffmpeg_testClass, SLOT(slot_open_camera()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), ffmpeg_testClass, SLOT(slot_close_camera()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), ffmpeg_testClass, SLOT(vedio_player()));

        QMetaObject::connectSlotsByName(ffmpeg_testClass);
    } // setupUi

    void retranslateUi(QMainWindow *ffmpeg_testClass)
    {
        ffmpeg_testClass->setWindowTitle(QApplication::translate("ffmpeg_testClass", "ffmpeg_test", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("ffmpeg_testClass", "IPC\347\233\270\346\234\272", Q_NULLPTR)
         << QApplication::translate("ffmpeg_testClass", "\345\244\247\346\201\222\347\233\270\346\234\272", Q_NULLPTR)
         << QApplication::translate("ffmpeg_testClass", "4K\347\233\270\346\234\272", Q_NULLPTR)
        );
        label->setText(QApplication::translate("ffmpeg_testClass", "\347\233\270\346\234\272URL", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("ffmpeg_testClass", "rtsp://admin:hk123456@192.168.0.11", Q_NULLPTR));
        label_2->setText(QApplication::translate("ffmpeg_testClass", "\350\276\223\345\207\272\350\267\257\345\276\204", Q_NULLPTR));
        lineEdit_2->setText(QApplication::translate("ffmpeg_testClass", "G:\\\\test.avi", Q_NULLPTR));
        label_image->setText(QApplication::translate("ffmpeg_testClass", "TextLabel", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("ffmpeg_testClass", "\347\273\223\346\235\237\345\275\225\345\203\217", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ffmpeg_testClass", "\345\274\200\345\247\213\345\275\225\345\203\217", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("ffmpeg_testClass", "\346\211\223\345\274\200\347\233\270\346\234\272", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("ffmpeg_testClass", "\347\273\223\346\235\237\346\230\276\347\244\272", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("ffmpeg_testClass", "\346\222\255\346\224\276\350\247\206\351\242\221", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ffmpeg_testClass: public Ui_ffmpeg_testClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FFMPEG_TEST_H
