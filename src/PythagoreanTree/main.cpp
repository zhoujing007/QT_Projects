#include "PythagoreanTree.h"
#include <QtWidgets/QApplication>
#include "logger.h"

#ifndef _DEBUG
#pragma comment(lib,"Logger.lib")
#else
#pragma comment(lib,"Loggerd.lib")
#endif

int lengthOfLongestSubstring(std::string s);

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    LogInfo("nihao");
    //     PythagoreanTree w;
    //     w.show();
    //lengthOfLongestSubstring("asgfhagfaaaa");

    return a.exec();
}

int lengthOfLongestSubstring(std::string s) {

    int start(0), end(0), length(0), result(0);
    int sSize = int(s.size());
    while (end < sSize) {
        char tmpChar = s[end];
        for (int index = start; index < end; index++) {
            if (tmpChar == s[index]) {
                start = index + 1;
                length = end - start;
                break;
            }
        }

        end++;
        length++;
        result = std::max(result, length);
    }
    return result;

}