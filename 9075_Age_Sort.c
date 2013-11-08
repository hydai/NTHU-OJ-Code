#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int N, i, X;
    while (~scanf("%d", &N) && N) {
        int List[101] = {0};
        int space = 0;
        while (N--) {
            scanf("%d", &X);
            List[X]++;
        }
        for (i = 0; i <= 100; i++) {
            while (List[i]!=0) {
                if (space++) {
                    putchar(' ');
                }
                printf("%d", i);
                List[i]--;
            }
        }
        putchar(10);
    }
    return 0;
}
