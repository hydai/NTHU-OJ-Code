#include <stdio.h>
int main(int argc, char *argv[])
{
    long long int n;
    while (~scanf("%lld", &n)) {
        long long int ans = 0;
        for(long long int i = 1; i <= n; i++) {
            ans+=(n%i);
            ans%=1000000009LL;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
