#include "mix_qss_change.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    mix_qss_change w;
    w.show();
    return a.exec();
}
