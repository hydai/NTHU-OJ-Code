#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    short arr_fact[1001] = {};
    int time, n, q, i, j, in[1001][1001], prefix[1001][1001], tmp, ans;
    int a1, a2, b1, b2;
    int fact;
    /* build list */
    for (i = 1; i < 1001; i++) {
        fact = 0;
        for (j = 1; j <= i; j++) {
            if (i%j==0) {
                fact++;
            }
        }
        arr_fact[i] = (fact%2==1)?1:0;
    }

    time = 0;
    while (~scanf("%d%d", &n, &q)) {
        memset(in, 0, sizeof(in)), memset(prefix, 0, sizeof(prefix));
        ans = 0;
        if (n==0 && q==0) {
            break;
        }
        time++;
        printf("Case #%d:\n", time);

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                scanf("%d", &tmp);
                in[i][j] = arr_fact[tmp];
                if (i!=0) {
                    prefix[i][j] += in[i][j]+prefix[i-1][j];
                }
                else {
                    prefix[i][j] += in[i][j];
                }
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 1; j < n; j++) {
                prefix[i][j] += prefix[i][j-1];
            }
        }

        while (q--) {
            scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
            a1--, a2--, b1--, b2--;
            ans = prefix[b1][b2] - (a2-1>=0?prefix[b1][a2-1]:0) - (a1-1>=0?prefix[a1-1][b2]:0) + (((a2-1>=0)&&(a1-1>=0))?prefix[a1-1][a2-1]:0);
            printf("%d\n", ans);
        }

    }

    return 0;
}
