/********************************************************************************
** Form generated from reading UI file 'media_player_test.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIA_PLAYER_TEST_H
#define UI_MEDIA_PLAYER_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_media_player_testClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *media_player_testClass)
    {
        if (media_player_testClass->objectName().isEmpty())
            media_player_testClass->setObjectName(QStringLiteral("media_player_testClass"));
        media_player_testClass->resize(600, 400);
        menuBar = new QMenuBar(media_player_testClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        media_player_testClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(media_player_testClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        media_player_testClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(media_player_testClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        media_player_testClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(media_player_testClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        media_player_testClass->setStatusBar(statusBar);

        retranslateUi(media_player_testClass);

        QMetaObject::connectSlotsByName(media_player_testClass);
    } // setupUi

    void retranslateUi(QMainWindow *media_player_testClass)
    {
        media_player_testClass->setWindowTitle(QApplication::translate("media_player_testClass", "media_player_test", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class media_player_testClass: public Ui_media_player_testClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIA_PLAYER_TEST_H
