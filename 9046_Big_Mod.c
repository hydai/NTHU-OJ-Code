#include <stdio.h>

#define LLI long long int

LLI bigMod(LLI B, LLI P, LLI M) {
    if (P == 0) {
        return 1;
    }
    else if (P == 1) {
        return B%M;
    }
    else {
        LLI tmp = bigMod(B, P/2, M);
        if (P % 2) {
            return tmp*tmp*B%M;
        }
        else {
            return tmp*tmp%M;
        }
    }
}

int main(int argc, char *argv[])
{
    LLI B, P, M;
    while (~scanf("%lld%lld%lld", &B, &P, &M)) {
        printf("%lld\n", bigMod(B, P, M));
    }
    return 0;
}
