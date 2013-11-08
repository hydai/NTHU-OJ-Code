#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 30000
short IsUsed[MAX_LEN];
short remain[MAX_LEN];

int main(int argc, char *argv[])
{
    int up, down, count, i, no_repeat_count;
    while (~scanf("%d%d", &up, &down)) {
        memset(IsUsed, 0, sizeof(IsUsed)), memset(remain, 0, sizeof(remain));
        printf("%d/%d = %d.", up, down, up/down);
        up%=down, up*=10;
        count = 0, no_repeat_count = 0;
        /* make a circle check of the remainnumber */
        while (!IsUsed[up]) {
            IsUsed[up] = 1;
            remain[count++] = up;
            up%=down, up*=10;
        }
        for (i = 0; remain[i]!=up; i++) { /* print no repeating digits */
            putchar('0'+remain[i]/down);
            no_repeat_count++;
        }
        putchar('(');
        while (i < count) {
            /* print remain repeating digits*/
            putchar('0'+remain[i]/down);
            i++;
            if (i>=50) {
                putchar('.');
                putchar('.');
                putchar('.');
                break;
            }
        }
        putchar(')'), putchar('\n');
    }
    return 0;
}
