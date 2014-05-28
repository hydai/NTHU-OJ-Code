#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
using namespace std;
map <char, char> MP;
map <char, char> rMP;
void init() {
    for (int i = 'A'; i <= 'Z'; i++) {
        MP[i] = 'A'+(i-'A')*2;
        rMP['A' + (i-'A')*2] = i;
    }
    for (int i = 'a'; i <= 'z'; i++) {
        MP[i] = 'A'+(i-'a')*2+1;
        rMP['A' + (i-'a')*2 + 1] = i;
    }
}
string mmp(string str) {
    string ss = "";
    char sss[1000] = {0};
    for (int i = 0; i < str.length(); i++) {
        sss[i] = MP[str[i]];
    }
    ss = sss;
    return sss;
}
string rmp(string str) {
    string ss = "";
    char sss[1000] = {0};
    for (int i = 0; i < str.length(); i++) {
        sss[i] = rMP[str[i]];
    }
    ss = sss;
    return sss;
}
int main(int argc, char *argv[])
{
    init();
    string a, b;
    while (cin >> a >> b) {
        string ra = mmp(a);
        string rb = mmp(b);
        if (ra < rb) {
            cout << rmp(ra) << " " << rmp(rb) << endl;
        } else {
            cout << rmp(rb) << " " << rmp(ra) << endl;
        }
    }
    return 0;
}
