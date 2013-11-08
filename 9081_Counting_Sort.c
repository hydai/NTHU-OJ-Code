#include <stdio.h>
#include <string.h>

#define MAX 10000+1

int main(int argc, char *argv[])
{
    int N, X, i;
    while (~scanf("%d", &N)) {
        int Array[MAX] = {0}, space = 0;
        while (N--) {
            scanf("%d", &X);
            Array[X]++;
        }
        for (i = 0; i < MAX; i++) {
            if (space && Array[i]) {
                putchar(32);
            }
            if (Array[i]) {
                space = 1;
                printf("%d %d", Array[i], i);
            }
        }
        putchar(10);
    }
    return 0;
}
