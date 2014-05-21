#include <stdio.h>

const long long int mFact = 10007LL;

long long int BM(long long int a, long long int b) {
    if (b < 2) {
        return a % mFact;
    }
    long long int tmp = BM(a, b/2LL) % mFact;
    if (b % 2 == 0) {
        return (tmp*tmp)%mFact;
    }
    else {
        return (((tmp*tmp)%mFact)*a)%mFact;
    }
}

int main(int argc, char *argv[])
{
    long long int a, b;
    while (~scanf("%lld%lld", &a, &b)) {
        printf("%lld\n", BM(a, b)%mFact);
    }
    return 0;
}
