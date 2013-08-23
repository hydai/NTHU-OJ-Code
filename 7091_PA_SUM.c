#include <stdio.h>
#include <stdlib.h>

#define MAX 10000+20

int main(int argc, char *argv[])
{
    int k, n, q, arr[MAX], sum[MAX], i, a, b;
    scanf("%d", &k);
    while (k--) {
        memset(arr, 0, sizeof(arr));
        memset(sum, 0, sizeof(sum));

        scanf("%d%d", &n, &q);
        arr[0] = sum[0] = 0;
        for (i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
            sum[i] = sum[i-1]+arr[i];
        }
        for (i = 0; i < q; i++) {
            scanf("%d%d", &a, &b);
            printf("%d\n", sum[b]-sum[a-1]);
        }
    }
    return 0;
}
