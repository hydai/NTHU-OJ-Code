#include <stdio.h>

int gcd (int a, int b)
{
    if (b) {
        while ((a%=b)&&(b%=a)) ;
    }
    return a+b;
}

int main(int argc, char *argv[])
{
    int a, b, factor;
    while (~scanf("%d%d", &a, &b)) {
        factor = gcd(a, b);
        a /= factor;
        b /= factor;
        printf("%d/%d\n", a, b);
    }
    return 0;
}
