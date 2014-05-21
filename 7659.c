#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LLI long long int
LLI a, r, n, m;
LLI big_mod(LLI nn) {
    if (nn == 0) {
        return 1;
    }
    if (nn == 1) {
        return r;
    }
    if (nn%2==0) {
        LLI tmp = (big_mod(nn/2));
        return (tmp*tmp)%m;
    }
    else {
        LLI tmp = (big_mod((nn-1)/2));
        return ((tmp*tmp))*r%m;
    }
}
int main(int argc, char *argv[])
{
    while (~scanf("%lld%lld%lld%lld", &a, &r, &n, &m)) {
        LLI tmp = 0;
        LLI i;
        for (i = 0; i < n; i++) {
            tmp = (tmp + (a*big_mod(i)))%m;
        }
        printf("%lld\n", tmp);
    }
    return 0;
}
