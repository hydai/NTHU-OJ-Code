#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LLI long long int
int cmp(const void *s1, const void *s2) {
    LLI a = *(LLI*)s1;
    LLI b = *(LLI*)s2;
    return a > b;
}
LLI GCD(LLI a, LLI b) {
    while ((a %= b) && (b %= a));
    return (a==0)?b:a;
}
LLI LCM(LLI a, LLI b, LLI tmp) {
    return a*(b/tmp);
}

int main(int argc, char *argv[])
{
    int n, i;
    LLI a, b, c, tmp, gcd1, gcd2, lcm1, lcm2;
    LLI input[3];
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%lld%lld%lld\n", &a, &b, &c);
        gcd1 = GCD(a, b);
        lcm1 = LCM(a, b, gcd1);
        gcd2 = GCD(gcd1, c);
        lcm2 = LCM(lcm1, c, GCD(lcm1, c));
        printf("%lld %lld\n", gcd2, lcm2);
    }
    return 0;
}
