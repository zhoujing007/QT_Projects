#ifndef MIX_QSS_CHANGE_H
#define MIX_QSS_CHANGE_H

#include <QtWidgets/QMainWindow>
#include "ui_mix_qss_change.h"

class mix_qss_change : public QMainWindow {
    Q_OBJECT

public:
    mix_qss_change(QWidget* parent = 0);
    ~mix_qss_change();

private:
    Ui::mix_qss_changeClass ui;

private slots:
    void change_qss(QString cur_file);
    void mouse_click();
};

#endif // MIX_QSS_CHANGE_H
