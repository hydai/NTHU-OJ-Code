#include <stdio.h>

int f[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181};

int main(int argc, char *argv[])
{
    int x, y, ans;
    while (~scanf("%d%d%d", &x, &y, &ans)) {
        printf("%d\n", f[ans-1]);
    }
    return 0;
}
