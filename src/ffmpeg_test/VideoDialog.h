#pragma once

#include <QDialog>
#include "ui_VideoDialog.h"

class VideoDialog : public QDialog {
    Q_OBJECT

public:
    VideoDialog(QWidget* parent = Q_NULLPTR);
    ~VideoDialog();

private:
    Ui::VideoDialog ui;
private slots:
    void open_local_file();
    void play_video();
};
