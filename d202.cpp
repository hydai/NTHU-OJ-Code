#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string str[2];
string num[4];
string ans[2];
void getAA();
void calc() {
    int len = (num[1].length() > num[3].length())?num[1].length():num[3].length();
    int *arr = new int[len+10];
    int ii = 0, jj = 0, kk = 0;
    while (ii < num[1].length() && jj < num[3].length()) {
        arr[kk++] = num[1][ii++] - '0' + num[3][jj++] - '0';
    }
    while (ii < num[1].length()) {
        arr[kk++] = num[1][ii++];
    }
    while (jj < num[3].length()) {
        arr[kk++] = num[3][jj++];
    }
    for (int i = 199; i > 0; i--) {
        arr[i-1] += arr[i]/10;
        arr[i] %= 10;
    }
    int carry = arr[0]/10;
    arr[0] %= 10;
    int len2 = (num[0].length() > num[2].length())?num[0].length():num[2].length();
    int *arr2 = new int[len2+10];
    ii = 0, jj = 0, kk = 0;
    while (ii < num[0].length() && jj < num[2].length()) {
        arr2[kk++] = num[0][ii++] - '0' + num[2][jj++] - '0';
    }
    while (ii < num[0].length()) {
        arr2[kk++] = num[0][ii++];
    }
    while (jj < num[2].length()) {
        arr2[kk++] = num[2][jj++];
    }
    arr2[kk-1]+=carry;
    for (int i = len2; i > 0; i--) {
        arr2[i-1] += arr2[i]/10;
        arr2[i] %= 10;
    }
    carry = arr2[0]/10;
    arr2[0] %= 10;
    if (carry) {
        printf("%d", carry);
    }
    for (int i = 0; i < len; i++) {
        printf("%d", arr[i]);
    }
    if (len2) {
        printf(".");

    }
}
int main(int argc, char *argv[])
{
    while (cin >> str[0] >> str[1]) {
        getAA();
        calc();
        print();
    }
    return 0;
}
void getAA() {
    int i;
    for (int k = 0; k < 2; k++) {
        num[0+2*k] = "";
        num[1+2*k] = "";
        for (i = 0; i < str[k].length(); i++) {
            if (str[k][i] == '.') {
                i++;
                break;
            }
            num[0+2*k].push_back(str[k][i]);
        }
        for (; i < str[k].length(); i++) {
            num[1+2*k].push_back(str[k][i]);
        }
    }
}
