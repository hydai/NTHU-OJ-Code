#include <stdio.h>
int main(int argc, char *argv[])
{
    int t, i, j;
    scanf("%d", &t);
#ifndef USE_CALCULUS
    while (t--) {
        long long int r, g[502] = {0};
        long long int min = 2147483647LL*2147483647LL, tmp, tmp2;
        scanf("%lld", &r);
        for (i = 0; i < r; i++) {
            scanf("%lld", &tmp);
            g[tmp]++;
        }
        tmp2 = 2147483647LL*2147483647LL;
        for (i = 0; i <= 500; i++) {
            tmp = 0;
            for (j = 0; j <= 500; j++) {
                tmp += (i-j)*(i-j)*g[j];
            }
            if (tmp < tmp2) {
                min = i;
                tmp2 = tmp;
            }
        }
        printf("%lld %lld\n", tmp2, min);
    }
#else
    while (t--) {
        long long int r, b = 0, ans = 0, tmp, c = 0;
        scanf("%lld", &r);
        for (i = 0; i < r; i++) {
            scanf("%lld", &tmp);
            b += (-tmp);
            c = tmp*tmp;
        }
        ans = (b/(2.0*r)+0.5);
        tmp = 0;
        printf("%lld %lld\n", r*ans*ans-2*(-b)*ans+c, ans);
    }
#endif

    return 0;
}
