/********************************************************************************
** Form generated from reading UI file 'redo_undo.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REDO_UNDO_H
#define UI_REDO_UNDO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <undotablewidget.h>

QT_BEGIN_NAMESPACE

class Ui_redo_undoClass
{
public:
    QGridLayout *gridLayout;
    UndoTableWidget *tableWidget;
    QPushButton *pushButton;

    void setupUi(QWidget *redo_undoClass)
    {
        if (redo_undoClass->objectName().isEmpty())
            redo_undoClass->setObjectName(QStringLiteral("redo_undoClass"));
        redo_undoClass->resize(600, 400);
        gridLayout = new QGridLayout(redo_undoClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableWidget = new UndoTableWidget(redo_undoClass);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget->rowCount() < 4)
            tableWidget->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem6);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setMouseTracking(true);
        tableWidget->setFocusPolicy(Qt::StrongFocus);
        tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);

        gridLayout->addWidget(tableWidget, 1, 0, 1, 1);

        pushButton = new QPushButton(redo_undoClass);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);


        retranslateUi(redo_undoClass);
        QObject::connect(pushButton, SIGNAL(clicked()), redo_undoClass, SLOT(save_data()));

        QMetaObject::connectSlotsByName(redo_undoClass);
    } // setupUi

    void retranslateUi(QWidget *redo_undoClass)
    {
        redo_undoClass->setWindowTitle(QApplication::translate("redo_undoClass", "redo_undo", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("redo_undoClass", "Q", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("redo_undoClass", "W", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("redo_undoClass", "E", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("redo_undoClass", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("redo_undoClass", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("redo_undoClass", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("redo_undoClass", "4", Q_NULLPTR));
        pushButton->setText(QApplication::translate("redo_undoClass", "\344\277\235\345\255\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class redo_undoClass: public Ui_redo_undoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REDO_UNDO_H
