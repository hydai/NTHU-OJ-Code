#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int t, initial, base;
    scanf("%d", &t);
    while (t--) {
        int result[100] = {0};
        int index = 0, i;
        scanf("%d%d", &initial, &base);
        if (initial == 0) {
            puts("0");
            continue;
        }
        while (initial) {
            result[index++] = initial % base;
            initial /= base;
        }

        for (i = index-1; i >= 0; i--) {
            putchar(result[i]+'0');
        }
        putchar(10);
    }
    return 0;
}
