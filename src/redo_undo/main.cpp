#include "redo_undo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	redo_undo w;
	w.show();
	return a.exec();
}
