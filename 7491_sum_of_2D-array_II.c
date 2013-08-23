#include <stdio.h>
#include <stdlib.h>

#define MAX 200

int arr[MAX][MAX];

int main(int argc, char *argv[])
{
    int n, q, a1, a2, b1, b2, times=0;
    int i, j, tmp;
    int ans;
    while (EOF!=scanf("%d%d", &n, &q)) {
        if (n == 0 && q == 0) {
            break;
        }
        else {
            times++;
            printf("Case #%d:\n", times);
        }

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                scanf("%d", &arr[i][j]);
            }
        }

        while (q > 0) {
            q--;
            scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
        
            ans = 0;
            if (a1 > b1) {
                tmp = a1;
                a1 = b1;
                b1 = tmp;
            }
            if (a2 > b2) {
                tmp = a2;
                a2 = b2;
                b2 = tmp;
            }

            for (i = a1-1; i < b1; i++) {
                for (j = a2-1; j < b2; j++) {
                    ans += arr[i][j];
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
