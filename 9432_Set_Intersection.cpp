#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int main(int argc, char *argv[])
{
    int n, tmp;
    map<int, int> m1, m2;
    while (~scanf("%d", &n) && n != 0) {
        m1.clear(); m2.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            if (m1.find(tmp) != m1.end()) {
                m1[tmp]++;
            }
            else {
                m1[tmp] = 1;
            }
        }
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            if (m2.find(tmp) != m2.end()) {
                m2[tmp]++;
            }
            else {
                m2[tmp] = 1;
            }
        }
        map<int, int>::iterator iterA, iterB;
        iterA = m1.begin();
        iterB = m2.begin();
        int space = 0;
        while (iterA != m1.end() && iterB != m2.end()) {
            if (iterA->first != iterB->first) {
                if (iterA->first > iterB->first) {
                    iterB++;
                }
                else {
                    iterA++;
                }
            }
            else {
                int num = (iterA->second > iterB->second)?(iterB->second):(iterA->second);
                for (int i = 0; i < num; i++) {
                    if (space++) putchar(' ');
                    printf("%d", iterA->first);
                }
                iterA++;
                iterB++;
            }
        }
        if (space == 0)
            puts("empty");
        else {
            putchar('\n');
        }
    }
    return 0;
}
