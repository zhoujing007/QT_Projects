#include "ffmpeg_test.h"
#include <QtWidgets/QApplication>

//vlc
#pragma comment(lib,"libvlc.lib")
#pragma comment(lib,"libvlccore.lib")

#pragma comment(lib,"VLCQtCore.lib")
#pragma comment(lib,"VLCQtWidgets.lib")
//ffmpeg
#pragma comment(lib,"avcodec.lib")
#pragma comment(lib,"avdevice.lib")
#pragma comment(lib,"avfilter.lib")
#pragma comment(lib,"avformat.lib")
#pragma comment(lib,"avutil.lib")
//opencv
#pragma comment(lib,"opencv_world310.lib")

#pragma comment(lib,"GxIAPI.lib")
#pragma comment(lib,"DxImageProc.lib")

#pragma comment(lib,"logger.lib")

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    ffmpeg_test w;
    w.show();
    return a.exec();
}
