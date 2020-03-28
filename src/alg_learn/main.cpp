#include <stdlib.h>
#include <iostream>
#include<vector>
#include<string>
#include <regex>
#include <assert.h>
#include <cstdio>

using namespace std;
// 2最大公因数为1
bool maxNum2(int a, int b) {
    int t = 0;
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else if (a < b) {
            b = b - a;
        }
    }
    if (a == 1) {
        return true;
    }
    return false;
}
// 3最大公因数为1
bool maxNum3(int a, int b, int c) {
    if (maxNum2(a, b) && maxNum2(a, c) && maxNum2(b, c)) {
        return true;
    }
    return false;
}

bool judge(int a, int b, int c) {
    if (a * a + b * b == c * c) {
        return true;
    }
    return false;
}

int NumData(int a) {
    if (a < 10) return 1;
    else {
        return NumData(a / 10) + 1;
    }
}

bool loop_show(std::vector<int> arr) {
    int len = arr.size();
    int i, j ;
    if (arr[0] < 10) {
        i = 0;
        j = 1;
    } else {
        i = 1;
        j = 0;
    }
    while (i < len && j < len) {
        if (arr[i] < 10) {
            i += 2;
        } else {
            return false;
        }
        //奇数位上寻找非奇数
        if (arr[j] > 9) {
            j += 2;
        } else {
            return false;
        }
    }
    return true;
}
bool continuity_show(std::vector<int> arr) {
    int len = arr.size();
    if (arr[0] < 10) {
        if (arr[len - 1] > 9) {
            return false;
        }
        for (int i = 1; i < len - 1; i++) {
            if (arr[i] < 10) {
                return false;
            }
        }
    } else {
        if (arr[len - 1] < 10) {
            return false;
        }
        for (int i = 1; i < len - 1; i++) {
            if (arr[i] > 9) {
                return false;
            }
        }
    }
    return true;
}

bool isLetter(std::string& inputtext) {
    tr1::regex reg("^[A-Za-z]+$");
    bool bValid = tr1::regex_match(inputtext, reg);

    return bValid;
}

bool isNumber(std::string& inputtext) {
    tr1::regex reg("^[0-9]+$");
    bool bValid = tr1::regex_match(inputtext, reg);

    return bValid;
}

void BubbleSort(vector<int>& a, vector<string>& b, size_t n) {
    size_t end = n;
    int exchange = 0;
    while (end > 0) { //end作为每趟排序的终止条件
        for (size_t i = 1; i < end; ++i) {
            if (a[i - 1] > a[i]) {
                swap(a[i - 1], a[i]);
                swap(b[i - 1], b[i]);
                exchange = 1;
            }
        }
        if (0 == exchange)//数组本身为升序，如果一趟排序结束，并没有进行交换，那么直接跳出循环（减少循环次数，升高效率）
            break;
        --end;
    }
}

void Bubble_Sort(vector<int>& A, vector<string>& b, int len) {
    for (int i = 1; i < len; i++)
        for (int j = 0; j < len - i; j++) {
            if (A[j] > A[j + 1]) {
                int t = A[j + 1];
                A[j + 1] = A[j];
                A[j] = t;
                swap(b[j], b[j + 1]);
            }
        }
}

//求阶乘 采用递归求解
int diGui(int temp) {
    if (temp == 1 || temp == 0) {
        return 1;
    } else {
        return temp * diGui(temp - 1);
    }
}

int lastWordLength(string s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    int i = len - 1;
    int res = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == ' ')
            break;
        else
            res++;
    }
    return res;
}
int lengthOfLongestSubstring(string s) {

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
        result = max(result, length);
    }
    return result;

}


void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partion(int arr[], int low, int high) {
    int privot = arr[low];          //选择第一个元素作为基准
    //推动左右指针向中间移动，即将基准移动到中间，low和high中的某一个一定是指向基准的
    while (low < high) {
        while ((low < high) && arr[high] >= privot)             //如果右边的数比基准大，则不用移动，否则将其交换到左边去
            high--;
        swap(arr, low, high);
        while ((low < high) && arr[low] <= privot)
            low++;
        swap(arr, low, high);
    }
    return low;         //当low=high的时候则停止划分，由于low和high在移动的过程中，总有一个是指向基准的，这里返回，low其实就是基准在数组中的索引
}
//递归划分，当划分到一个元素的时候，子数组就是有序的
void QSort(int arr[], int low, int high) {
    if (low < high) {
        int idx = partion(arr, low, high);
        //递归划分划分左右子数组，让左右子数组有序
        QSort(arr, low, idx - 1);
        QSort(arr, idx + 1, high);
    }
}
void QucikSort(int arr[], int n) {
    QSort(arr, 0, n - 1);
}

int main() {
    //勾股定理
    /*  如果三个正整数(a, b, c) 满足 a ^ 2 + b ^ 2 = c ^ 2 的关系，则称(a, b, c) 为勾股数，为了探索规律，定义如果(a, b, c) 之间两两互质，则为勾股数元祖（例如(3, 4, 5) 是，(6, 8, 10) 则不是）。
        请求出给定范围[N, M] 内，所有勾股数元祖。
        输入描述
        N 属于[1, 200]
        M 属于(N, M];
        输出描述
        (a, b, c) 请保证 a < b < c, 输出格式：a b c;
        多组勾股数元祖按照 a 升序，b 升序，最后 c 升序的方式排序输出；
        给定范围内找不到勾股数元祖，输出”NA”。*/
    /*int n, m;
    cin >> n;
    cin >> m;
    for (int i = n; i <= m - 2; i++) {
        for (int j = i + 1; j <= m - 1; j++) {
            if (maxNum2(i, j)) {
                for (int k = j + 1; k <= m; k++) {
                    if (maxNum3(i, j, k) && judge(i, j, k)) {
                        cout << i << " " << j << " " << k << endl;
                    }
                }
            }
        }
    }*/

    //数据合并
    /*现在有多组整数数组，需要将他们合并成一个新的数组。合并规则，
        从每个数组里按顺序取出固定长度的内容合并到新的数组中，取完的内容会删除掉，
        如果该行不足固定长度或者已经为空，则直接取出剩余部分的内容放到新的数组中，
        继续下一行。如样例1，获得长度3，先遍历第一行，获得2, 5, 6；再遍历第二行，获得1, 7, 4；
        再循环回到第一行，获得7, 9, 5；再遍历第二行，获得3, 4；再回到第一行，获得7，按顺序拼接成最终结果。输入描述：
        第一行是每次读取的固定长度，长度>0；第2 - n行是需要合并的数组，不同的数组用回车换行分隔，数组内部用逗号分隔。
        输出描述：输出一个新的数组，用逗号分隔。输入：32, 5, 6, 7, 9, 5, 7   1, 7, 4, 3, 4输出：2, 5, 6, 1, 7, 4, 7, 9, 5, 3, 4, 7*/

    /*string temp;
    string res;
    vector<string> array;
    int clen = 0;//每次截取字符串长度
    cin >> clen;
    while (cin >> temp) { //vector接收字符串
        array.push_back(temp);
    }
    int flag = 0, pos = 0;
    int num = 0;//，计数
    while (1) { //循环截取每行字符串中的元素，直到所有字符串为空
        flag = 0;
        int size = array.size();
        for (int i = 0; i < size; ++i) { //选取某一行元素
            num = 0;

            if (!array[i].empty()) { //如果该字符串不为空则进入
                flag = 1;
                while (num != clen) {
                    pos = array[i].find(',');
                    if (pos != -1) {
                        num++;
                        res += array[i].substr(0, pos + 1);
                        array[i] = array[i].erase(0, pos + 1);//删除字符串
                    } else
                        break;
                }
                if (num != clen) { //如果','长度不够clen
                    res += array[i];
                    res += ',';
                    array[i].clear();
                }

            }

        }
        if (flag == 0) {
            break;
        }
    }
    res = res.erase(res.size() - 1);
    cout << res << endl;*/


    /*
    一个序列是由N个整数组成，这些数的范围大于0，小于100，规则：
    1.如果数字是以个位和两位数交替出现，则认为合法
    2.如果第一个和最后一个都是两位数，中间的是一位数，则认为合法
    3.如果第一个和最后一个都是一位数，中间是两位数，则认为合法，
    例：1 23 34 2 输出true，33 1 32 2输出true
    */
    /*string res;
    vector<int> array;
    int temp ;//每次截取字符串长度
    while (cin >> temp) { //vector接收字符串
        if (temp < 0 || temp > 100)
            cout << "数字越界，重新输入" << endl;
        array.push_back(temp);
    }
    int size = array.size();
    if (size > 1) {
        if (loop_show(array) || continuity_show(array)) {
            res = "true";
        } else {
            res = "false";
        }
    } else {
        res = "仅有一个数字";
    }
    cout << res << endl;*/


    /*磁盘容量有M，G，T三个等级，换算关系为1T = 1000G，1G = 1000M，
    现对他们从小到大进行排序，例如输入1T，20M，3G，输出20M ，3G ，1T*/

    /*vector<string> array;
    string temp ;//每次截取字符串长度
    while (cin >> temp) { //vector接收字符串
        if (temp.size() < 2) {
            cout << "输入格式不正确，重新输入" << endl;
        }
        array.push_back(temp);
    }
    vector<int> compare_container;
    for (int i = 0; i < array.size(); i++) {
        string temp_str = array[i];
        string temp_count_str = temp_str.substr(0, temp_str.size() - 1);
        int temp_count = 0;
        bool is_number = isNumber(temp_count_str);
        if (is_number) {
            temp_count = std::atoi(temp_count_str.c_str());
        } else {
            cout << "字符格式不正确" << endl;
            break;
        }
        string unit = temp_str.substr(temp_str.size() - 1);
        if (!unit.compare("M")) {
            temp_count = temp_count;
        } else if (!unit.compare("G")) {
            temp_count = temp_count * 1000;
        } else if (!unit.compare("T")) {
            temp_count = temp_count * 1000000;
        } else {
            cout << "字符格式不正确" << endl;
            break;
        }
        compare_container.push_back(temp_count);
    }
    int n = compare_container.size();
    Bubble_Sort(compare_container, array, n);
    for (int i = 0; i < n; i++) { //数组输出
        cout << array[i] << "\t";
    }
    cout << endl;*/

    //判断最后一个字符大小
    //     string s;
    //     getline(cin, s);
    //     int len = 0;
    //     len = lastWordLength(s);
    //     cout << len;
    //     return 0;

    /*char str[10000];
    string str1;
    char ch;
    int len = 0;
    //gets(str);  
    getline(cin, str1);
    ch = getchar();

    //scanf("%c",&ch);    //使用scanf()函数输入字符也是可行的，
    //     for (int i = 0; i < strlen(str); i++) {
    //         if (str[i] == ch || str[i] == ch - 32 || str[i] == ch + 32)
    //             len++;
    //     }
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] == ch || str1[i] == ch - 32 || str1[i] == ch + 32)
            len++;
    }
    printf("%d\n", len);*/

    //     string temp;
    //     string temp2;
    //     getline(cin, temp);
    //     getline(cin, temp2);
    //     vector<string>str_s;
    //
    //     for (int i = 0; i < temp.size(); i++) {
    //         if ((i + 1) % 8 == 0) {
    //             cout << temp[i] << endl;
    //         } else {
    //             cout << temp[i];
    //         }
    //     }
    //     int aa = temp.size() % 8;
    //     if (aa != 0) {
    //         for (int i = 0; i < 8 - aa; i++) {
    //             cout << "0";
    //         }
    //         cout << endl;
    //
    //     }

    ////123321
    /*int num, tmp;
    int reverse = 0;

    cin >> num;

    if (num < 0) {
        num = -num;
    }

    tmp = num;

    while (tmp != 0) {
        reverse = reverse * 10 + tmp % 10;
        tmp /= 10;
    }

    if (num == reverse) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }*/

    //lengthOfLongestSubstring("123516789265");

    int arr[5] = { 2, 31, 1, 3, 0 };
    QucikSort(arr, 5);
    system("Pause");
    return 0;
}