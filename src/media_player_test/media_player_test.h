#ifndef MEDIA_PLAYER_TEST_H
#define MEDIA_PLAYER_TEST_H

#include <QtWidgets/QMainWindow>
#include "ui_media_player_test.h"

class media_player_test : public QMainWindow
{
	Q_OBJECT

public:
	media_player_test(QWidget *parent = 0);
	~media_player_test();

private:
	Ui::media_player_testClass ui;
};

#endif // MEDIA_PLAYER_TEST_H
