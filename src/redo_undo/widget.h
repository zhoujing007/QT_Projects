#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTableWidget>
#include<QComboBox>
#include<QBoxLayout>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    QTableWidget*tablewidget;
    QComboBox *combox;
    QHBoxLayout *hlayout;
    void unit();

};

#endif // WIDGET_H
