#include "widget.h"
#include<QBoxLayout>
#include<QString>
#include<QPushButton>
#include<QCheckBox>
#include<QItemDelegate>
#include<QDebug>
#include"questionlistdelegate.h"
#include<QHeaderView>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setFixedSize(800,600);
    hlayout = new QHBoxLayout;
    tablewidget = new QTableWidget(8,8);

    combox = new QComboBox;
    QPushButton *pushbutton = new QPushButton;
    QCheckBox *checkbox = new QCheckBox;

    QStringList string;
    string <<"1"<<"2"<<"3";

    combox->addItems(string);
    tablewidget->setCellWidget(1,1,pushbutton);
    tablewidget->setCellWidget(0,0,checkbox);
    tablewidget->setCellWidget(3,2,combox);


    unit();


   // tablewidget->verticalHeader()->setVisible(false);//隐藏垂直表头
   // tablewidget->setSelectionBehavior(QAbstractItemView::SelectRows);//选择一行
//    setItemIsEditable(tablewidget, 0);//禁止表格编辑
//    setItemIsEditable(tablewidget, 2);
//    setItemIsEditable(tablewidget, 3);
    questionlistdelegate* aa =  new questionlistdelegate();
   //tablewidget->setItemDelegateForColumn(1, new questionlistdelegate(this));//添加QCombox代理




    hlayout->addWidget(tablewidget);
    this->setLayout(hlayout);

}

Widget::~Widget()
{

}
void Widget::unit(){
    qDebug()<<"i love u"<<endl;
}
