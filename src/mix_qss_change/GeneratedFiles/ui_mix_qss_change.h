/********************************************************************************
** Form generated from reading UI file 'mix_qss_change.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIX_QSS_CHANGE_H
#define UI_MIX_QSS_CHANGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <tool_button.h>

QT_BEGIN_NAMESPACE

class Ui_mix_qss_changeClass
{
public:
    QAction *actionaa;
    QAction *actionaa_2;
    QAction *action12;
    QAction *actioncc;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    ToolButton *toolButton_3;
    ToolButton *toolButton_4;
    QSpacerItem *verticalSpacer;
    ToolButton *toolButton_2;
    QToolButton *toolButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QComboBox *style_commbox;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_4;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QComboBox *comboBox;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QSpinBox *spinBox_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QTableWidget *tableWidget_2;
    QLabel *label_3;
    QComboBox *comboBox_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;

    void setupUi(QMainWindow *mix_qss_changeClass)
    {
        if (mix_qss_changeClass->objectName().isEmpty())
            mix_qss_changeClass->setObjectName(QStringLiteral("mix_qss_changeClass"));
        mix_qss_changeClass->resize(1247, 636);
        actionaa = new QAction(mix_qss_changeClass);
        actionaa->setObjectName(QStringLiteral("actionaa"));
        actionaa_2 = new QAction(mix_qss_changeClass);
        actionaa_2->setObjectName(QStringLiteral("actionaa_2"));
        action12 = new QAction(mix_qss_changeClass);
        action12->setObjectName(QStringLiteral("action12"));
        actioncc = new QAction(mix_qss_changeClass);
        actioncc->setObjectName(QStringLiteral("actioncc"));
        centralWidget = new QWidget(mix_qss_changeClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(200, 0));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        toolButton_3 = new ToolButton(widget);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setMinimumSize(QSize(160, 110));

        gridLayout_2->addWidget(toolButton_3, 3, 0, 1, 1);

        toolButton_4 = new ToolButton(widget);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        toolButton_4->setMinimumSize(QSize(160, 110));

        gridLayout_2->addWidget(toolButton_4, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 130, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 5, 0, 1, 1);

        toolButton_2 = new ToolButton(widget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setMinimumSize(QSize(160, 100));
        toolButton_2->setMaximumSize(QSize(160, 100));

        gridLayout_2->addWidget(toolButton_2, 2, 0, 1, 1);

        toolButton = new QToolButton(widget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setMinimumSize(QSize(160, 100));

        gridLayout_2->addWidget(toolButton, 1, 0, 1, 1);

        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 50));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        style_commbox = new QComboBox(groupBox);
        style_commbox->setObjectName(QStringLiteral("style_commbox"));

        gridLayout_5->addWidget(style_commbox, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_4 = new QGridLayout(tab);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_4->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_4->addWidget(lineEdit, 0, 1, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_4->addWidget(label_2, 0, 2, 1, 1);

        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(100, 0));

        gridLayout_4->addWidget(comboBox, 0, 3, 1, 1);

        spinBox = new QSpinBox(tab);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimumSize(QSize(100, 0));

        gridLayout_4->addWidget(spinBox, 0, 4, 1, 1);

        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(150, 0));

        gridLayout_4->addWidget(pushButton, 0, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(173, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 6, 1, 1);

        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (tableWidget->rowCount() < 7)
            tableWidget->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem12);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout_4->addWidget(tableWidget, 1, 0, 1, 7);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(tab_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(lineEdit_2, 0, 1, 1, 1);

        spinBox_2 = new QSpinBox(tab_2);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(spinBox_2, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 6, 1, 1);

        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(pushButton_2, 0, 5, 1, 1);

        tableWidget_2 = new QTableWidget(tab_2);
        if (tableWidget_2->columnCount() < 9)
            tableWidget_2->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(6, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(7, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(8, __qtablewidgetitem21);
        if (tableWidget_2->rowCount() < 9)
            tableWidget_2->setRowCount(9);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(1, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(2, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(3, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(4, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(5, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(6, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(7, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(8, __qtablewidgetitem30);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));

        gridLayout_3->addWidget(tableWidget_2, 1, 0, 1, 7);

        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 0, 2, 1, 1);

        comboBox_2 = new QComboBox(tab_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(comboBox_2, 0, 3, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 1, 1, 1);

        mix_qss_changeClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mix_qss_changeClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1247, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        mix_qss_changeClass->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(actionaa);
        menu->addAction(actionaa_2);
        menu_2->addAction(action12);
        menu_3->addAction(actioncc);

        retranslateUi(mix_qss_changeClass);
        QObject::connect(style_commbox, SIGNAL(currentIndexChanged(QString)), mix_qss_changeClass, SLOT(change_qss(QString)));
        QObject::connect(toolButton_2, SIGNAL(clicked()), mix_qss_changeClass, SLOT(mouse_click()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mix_qss_changeClass);
    } // setupUi

    void retranslateUi(QMainWindow *mix_qss_changeClass)
    {
        mix_qss_changeClass->setWindowTitle(QApplication::translate("mix_qss_changeClass", "mix_qss_change", Q_NULLPTR));
        actionaa->setText(QApplication::translate("mix_qss_changeClass", "\346\226\207\344\273\266", Q_NULLPTR));
        actionaa_2->setText(QApplication::translate("mix_qss_changeClass", "\344\275\240\345\245\275", Q_NULLPTR));
        action12->setText(QApplication::translate("mix_qss_changeClass", "12", Q_NULLPTR));
        actioncc->setText(QApplication::translate("mix_qss_changeClass", "\345\270\256\345\212\251", Q_NULLPTR));
        toolButton_3->setText(QApplication::translate("mix_qss_changeClass", "\347\224\273\347\272\277", Q_NULLPTR));
        toolButton_4->setText(QApplication::translate("mix_qss_changeClass", "\345\205\263\351\227\255", Q_NULLPTR));
        toolButton_2->setText(QApplication::translate("mix_qss_changeClass", "\347\202\271\345\207\273", Q_NULLPTR));
        toolButton->setText(QApplication::translate("mix_qss_changeClass", "\345\274\200\345\247\213", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("mix_qss_changeClass", "\345\210\207\346\215\242\346\240\267\345\274\217", Q_NULLPTR));
        label->setText(QApplication::translate("mix_qss_changeClass", "\345\247\223\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("mix_qss_changeClass", "\347\217\255\347\272\247", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("mix_qss_changeClass", "1", Q_NULLPTR)
         << QApplication::translate("mix_qss_changeClass", "2", Q_NULLPTR)
         << QApplication::translate("mix_qss_changeClass", "3", Q_NULLPTR)
        );
        pushButton->setText(QApplication::translate("mix_qss_changeClass", "\347\241\256\345\256\232", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("mix_qss_changeClass", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("mix_qss_changeClass", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("mix_qss_changeClass", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("mix_qss_changeClass", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("mix_qss_changeClass", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("mix_qss_changeClass", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem11->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem12->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("mix_qss_changeClass", "1\346\234\210", Q_NULLPTR));
        label_4->setText(QApplication::translate("mix_qss_changeClass", "\345\247\223\345\220\215", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("mix_qss_changeClass", "\347\241\256\345\256\232", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem15->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem16->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem17->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem18->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_2->horizontalHeaderItem(6);
        ___qtablewidgetitem19->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_2->horizontalHeaderItem(7);
        ___qtablewidgetitem20->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_2->horizontalHeaderItem(8);
        ___qtablewidgetitem21->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_2->verticalHeaderItem(0);
        ___qtablewidgetitem22->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_2->verticalHeaderItem(1);
        ___qtablewidgetitem23->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_2->verticalHeaderItem(2);
        ___qtablewidgetitem24->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_2->verticalHeaderItem(3);
        ___qtablewidgetitem25->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_2->verticalHeaderItem(4);
        ___qtablewidgetitem26->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_2->verticalHeaderItem(5);
        ___qtablewidgetitem27->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_2->verticalHeaderItem(6);
        ___qtablewidgetitem28->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_2->verticalHeaderItem(7);
        ___qtablewidgetitem29->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_2->verticalHeaderItem(8);
        ___qtablewidgetitem30->setText(QApplication::translate("mix_qss_changeClass", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        label_3->setText(QApplication::translate("mix_qss_changeClass", "\347\217\255\347\272\247", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("mix_qss_changeClass", "1", Q_NULLPTR)
         << QApplication::translate("mix_qss_changeClass", "2", Q_NULLPTR)
         << QApplication::translate("mix_qss_changeClass", "3", Q_NULLPTR)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("mix_qss_changeClass", "2\346\234\210", Q_NULLPTR));
        menu->setTitle(QApplication::translate("mix_qss_changeClass", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("mix_qss_changeClass", "\351\200\211\351\241\271", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("mix_qss_changeClass", "\345\270\256\345\212\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mix_qss_changeClass: public Ui_mix_qss_changeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIX_QSS_CHANGE_H
