#include <cstdio>
#include <map>
#include <string>
#include <cstring>

using namespace std;
struct mystr
{
    bool operator()(string s1, string s2) const
    {
        string t1 = s1.substr(0,3);
        string t2 = s1.substr(3);
        string tt1 = s2.substr(0,3);
        string tt2 = s2.substr(3);
        if (t1 != tt1) {
            if (t1 < tt1) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            if (t2 != tt2) {
                if (t2 < tt2) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
        return false;
    }
};
int main(int argc, char *argv[])
{
    int t, n;
    scanf("%d", &t);
    for (int iii = 1; iii <= t; iii++) {
        char st[5], stt[4];
        map<string, int, mystr> M;
        M.clear();
        string tmp = "";
        bool isEmpty = true;
        printf("Case #%d\n", iii);
        scanf("%d", &n);
        while (n--) {
            char pp;
            tmp = "";
            scanf("%s%s", st, stt);
            tmp += st;
            if (!strcmp(stt, "S")) {
                pp = '1';
            }
            else if (!strcmp(stt, "M")) {
                pp = '2';
            }
            else if (!strcmp(stt, "L")) {
                pp = '3';
            }
            else if (!strcmp(stt, "X")) {
                pp = '4';
            }
            else {
                pp = '5';
            }
            tmp += pp;
            M[tmp]++;
        }
        for (map<string, int>::iterator iter = M.begin();
            iter != M.end();
            iter++) {
            if (iter -> second % 2 == 1) {
                isEmpty = false;
                string ttt = iter->first;
                string s1 = ttt.substr(0,3);
                string s2 = ttt.substr(3);
                printf("%s %s\n", s1.c_str(), 
                        (s2 == "1")?("S"):
                        ((s2 == "2")?("M"):
                         ((s2 == "3")?("L"):
                          ((s2 == "4")?("X"):("XL")))));
            }
        }
        if (isEmpty) {
            printf("Socks fine\n");
        }

    }
    return 0;
}
