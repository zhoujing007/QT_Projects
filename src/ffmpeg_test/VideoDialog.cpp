#include "VideoDialog.h"
#include <QFileDialog>
#include <QInputDialog>
#include "logger.h"

VideoDialog::VideoDialog(QWidget* parent)
    : QDialog(parent) {
    ui.setupUi(this);
}

VideoDialog::~VideoDialog() {
}

void VideoDialog::open_local_file() {
    QString file =
        QFileDialog::getOpenFileName(this, tr("Open file"),
                                     QDir::homePath(),
                                     tr("Multimedia files(*)"));

    if (file.isEmpty()) {
        LogInfo("ÎÞÂ·¾¶");
        return;
    } else {
        ui.lineEdit->setText(file);
    }
}

void VideoDialog::play_video() {
    QString cur_video_path = ui.lineEdit->text();
    ui.widget->set_url(cur_video_path);
}
