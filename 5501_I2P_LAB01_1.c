#include <stdio.h>

int main(int argc, char *argv[])
{
    int a, b, x, y;
    scanf("%d%d", &a, &b);
    x = (2*b-a)/6;
    y = (2*a-b)/6;
    printf("%d %d", x, y);
    return 0;
}
