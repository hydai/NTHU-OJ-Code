#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100000+30

int main(int argc, const char *argv[])
{
    int t, n, q, i;
    long long int arr[MAX_LEN], sum[MAX_LEN], a, b;
    
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(arr, 0, sizeof(arr));memset(sum, 0, sizeof(sum));
        scanf("%lld", &arr[0]);
        sum[0] = arr[0];
        for (i = 1; i < n; i++) {
            scanf("%lld", &arr[i]);
            sum[i]+=arr[i]+sum[i-1];
        }
        scanf("%d", &q);
        for (i = 0; i < q; i++) {
            scanf("%lld%lld", &a, &b);
            a--, b--;
            if (a==0) {
                printf("%lld\n", sum[b]);
            }
            else {
                printf("%lld\n", sum[b]-sum[a-1]);
            }
        }
    }
    return 0;
}
