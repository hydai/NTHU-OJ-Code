#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>

#define LLI long long
using namespace std;
LLI arr[55][35];
LLI pre[55][35];
int main(int argc, char *argv[])
{
    LLI w, b, num[55];
    int wct = 1, space = 0;
    while (~scanf("%lld", &w) && (w != 0)) {
        if (space++) {
            putchar(10);
        }
        printf("Workyards %d\n", wct++);
        for (int i = 0; i < w; i++) {
            scanf("%lld", &num[i]);
            pre[i][0] = 0;
            for (int j = 0; j < num[i]; j++) {
                scanf("%lld", &arr[i][j]);
                pre[i][j+1] = pre[i][j] + 10 - arr[i][j];
            }
        }
        LLI MAXN = 0;
        map<LLI, int> M;
        for (int i = 0; i < w; i++) {
            LLI MM = 0;
            LLI cat[1000] = {0};
            int cct = 1;
            for (int j = 1; j <= num[i]; j++) {
                if (MM < pre[i][j]) {
                    MM = pre[i][j];
                    cct = 0;
                    cat[cct++] = j;
                }
                else if (MM == pre[i][j]){
                    cat[cct++] = j;
                }
            }
            MAXN += MM;
            if (M.size() == 0) {
                for (int j = 0; j < cct; j++) {
                    M[cat[j]] = 1;
                }
            }
            else {
                map<LLI, int> tmpM;
                map<LLI, int>::iterator iter = M.begin();
                for (; iter != M.end(); iter++) {
                    for (int j = 0; j < cct; j++) {
                        tmpM[(iter->first + cat[j])] = 1;
                    }
                }
                iter = tmpM.begin();
                M.clear();
                for (int ii = 0; ii < 10 && iter != tmpM.end(); ii++, iter++) {
                    M[iter->first] = 1;
                }
            }
        }
        printf("Maximum profit is %lld.\n", MAXN);
        printf("Number of pruls to buy:");
        map<LLI, int>::iterator iter = M.begin();
        for (int ii = 0; ii < 10 && iter != M.end(); ii++, iter++) {
            printf(" %lld", iter->first);
        }
        putchar(10);
    }
    return 0;
}
