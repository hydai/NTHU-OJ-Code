#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
using namespace std;
int min_(int a, int b) {
    return (a>b)?b:a;
}
int main(int argc, char *argv[])
{
    int n, m, ct = 1, id, cct = 0;
    while (~scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0) {
            break;
        }
        map<string, int> M; M.clear();
        map<int, string> rM; rM.clear();
        int link[30][30];
        int AA[30][30] = {0};
        int flag[30] = {0};
        id = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                link[i][j] = 1000000000;
            }
        }
        if (cct++) putchar(10);
        printf("Calling circles for data set %d:\n", ct++);
        for (int i = 0; i < m; i++) {
            string a, b;
            cin >> a >> b;
            if (M.find(a) == M.end()) {
                rM[id] = a;
                M[a] = id++;
            }
            if (M.find(b) == M.end()) {
                rM[id] = b;
                M[b] = id++;
            }
            link[M[a]][M[b]] = 1;
            link[M[a]][M[a]] = 0;
            link[M[b]][M[b]] = 0;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    link[i][j] = min_(link[i][j], link[i][k]+link[k][j]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (link[i][j] == 1000000000) {
                    AA[i][j] = 0;
                } else {
                    AA[i][j] = 1;
                }
            }
        }
        /*
        putchar(10);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf(" %d", AA[i][j]);
            }
            putchar(10);
        }
        for (int i = 0; i < n; i++) {
            cout << i << rM[i] << endl;
        }
        */
        for (int i = 0; i < n; i++) {
            if (flag[i] == 0) {
                flag[i] = 1;
                cout << rM[i];
                for (int j = i+1; j < n; j++) {
                    if (AA[i][j] == 1 && AA[j][i] == 1) {
                        flag[j] = 1;
                        cout << ", " << rM[j];
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}
