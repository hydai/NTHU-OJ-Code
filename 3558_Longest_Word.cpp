#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>

using namespace std;
int main(int argc, char *argv[])
{
    string maxStr, str;
    string tmp;
    int maxLen = 0;
    while (cin >> tmp) {
        if (tmp == "E-N-D") {
            break;
        }
        int len = 0;
        str = "";
        for (string::iterator it = tmp.begin(); it != tmp.end(); it++) {
            if (isalpha(*it) || *it == '-') {
                len++;
                str+=*it;
            }
        }
        if (maxLen < len) {
            maxStr = str;
            maxLen = len;
        }
    }
    string::iterator it = maxStr.begin();
    for(; it != maxStr.end(); it++) {
        if (isupper(*it)) {
            putchar(tolower(*it));
        }
        else {
            putchar(*it);
        }
    }
    putchar(10);
    return 0;
}
