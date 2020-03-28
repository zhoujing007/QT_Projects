#include "mix_qss_change.h"
#include <QDir>

#pragma execution_character_set("utf-8")


static void setCurStyle(const QString& style) {
    QFile qss(style);
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();
}

static void setStyle(QWidget* w, QString file_path) {
    QFile qss(file_path);
    qss.open(QFile::ReadOnly);
    w->setStyleSheet(qss.readAll());
    qss.close();
}

mix_qss_change::mix_qss_change(QWidget* parent)
    : QMainWindow(parent) {
    ui.setupUi(this);
    this->showMaximized();
    //搜索当前目录下所有的qss文件
    QString search_path = QDir::currentPath();
    QDir dir("./qss");
    QStringList nameFilters;
    nameFilters << "*.qss";
    QStringList files = dir.entryList(nameFilters, QDir::Files | QDir::Readable, QDir::Name);
    for (int i = 0; i < files.size(); i++) {
        ui.style_commbox->addItem(files.at(i));
    }
    ui.toolButton_2->set_picture("jiaSu.png");
}

mix_qss_change::~mix_qss_change() {

}

void mix_qss_change::change_qss(QString cur_file) {
    QString path = "qss/" + cur_file;
    setCurStyle(path);
}

void mix_qss_change::mouse_click() {
    ui.toolButton_2->setMousePress(true);
}
