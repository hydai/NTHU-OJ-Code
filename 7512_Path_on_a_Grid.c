#include <stdio.h>
#include <stdlib.h>

typedef long long unsigned int llui;

int main(int argc, char *argv[])
{
    unsigned int in_a, in_b, i;
    llui total_up, min, ans;
    while (scanf("%u%u", &in_a, &in_b)) {
        if (in_a==0 && in_b==0) {
            break;
        }
        total_up = in_a + in_b;
        min = (in_a>in_b)?in_b:in_a;
        ans = 1;
        for (i = 1; i <= min; ans*=(total_up-i+1), ans/=i, i++){}
        printf("%llu\n", ans);
    }
    return 0;
}
