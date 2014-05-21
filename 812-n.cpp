#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int num[30+5];
long long arr[30+5][20+5];
long long pre[30+5][20+5];
int main(int argc, char *argv[])
{
int n;
int space = 0;
while(~scanf("%d", &n) && (n!=0)) {
    long long tt;
    long long FinalProfit = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        pre[i][0] = 0;
        for (int j = 1; j <= num[i]; j++) {
            scanf("%lld", &tt);
            arr[i][j] = 10 - tt;
            pre[i][j] = pre[i][j-1] + arr[i][j];
        }
    }
    long long MM = 0;
    long long MAXM = 0;
    long long ans[35][100];
    int cct[35];
    for (int i = 0; i < n; i++) {
        ans[i][0] = 0;
        cct[i]++;
    }
    for (int i = 0; i < n; i++) {
        MM = 0;
        for (int j = 0; j <= num[i]; j++) {
            if (pre[i][j] > MM) {
                MM = pre[i][j];
                cct[i] = 0;
                ans[i][cct[i]++] = j;
            }
            else if (pre[i][j] == MM){
                ans[i][cct[i]++] = j;
            }
        }
        MAXM += MM;
    }
    int ctt = 0
    runtimeRow[500];
    sort(ans[0], ans[0]+cct[0]);
    for (int i = 0; i < 10 && i < cct[0]; i++) {
        if (ans[0][i] > 0) {
            runtimeRow[i] = ans[0][i];
            ctt++;
        }
    }
    for (int ii = 1; ii < n; ii++) {
        long long tmpR[500] = {0};
        int tmpct = ctt; ctt = 0;
        for (int i = 0; i < tmpct; i++) {
            for (int j = 0; j < cct[ii]; j++) {
                if (runtimeRow[i] + ans[i][j] > 0)
                    tmpR[ctt++] = runtimeRow[i]+ans[i][j];
            }
        }
        sort(tmpR, tmpR+ctt);
        if (ctt > 0) {
            
        }

    }
    if (space++) {
        putchar(10);
    }
    
    printf("Workyards %d\n", n);
    printf("Maximum profit is %lld.\n", MAXM);
    printf("Number of pruls to buy:");
    for (int i = 0; i < tmp.size(); i++) {
        printf(" %lld", tmp[i]);
    }
    putchar(10);
}
return 0;
}
