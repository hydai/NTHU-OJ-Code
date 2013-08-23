#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100000+30

int main(int argc, const char *argv[])
{
    int t, n, q, arr[MAX_LEN], sum[MAX_LEN], a, b, i;
    
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(arr, 0, sizeof(arr));memset(sum, 0, sizeof(sum));
        scanf("%d", &arr[0]);
        sum[0] = arr[0];
        for (i = 1; i < n; i++) {
            scanf("%d", &arr[i]);
            sum[i]+=arr[i]+sum[i-1];
        }
        scanf("%d", &q);
        for (i = 0; i < q; i++) {
            scanf("%d%d", &a, &b);
            a--, b--;
            if (a==0) {
                printf("%d\n", sum[b]);
            }
            else {
                printf("%d\n", sum[b]-sum[a-1]);
            }
        }
    }
    return 0;
}
