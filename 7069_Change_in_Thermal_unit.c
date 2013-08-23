#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n,i;
    float c, d;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%f%f", &c, &d);
        c = c*9.0/5.0 + 32;
        c += d;
        c = (c - 32)*5.0/9.0;
        printf("Case %d: %.2f\n", i, c);
    }
    return 0;
}
