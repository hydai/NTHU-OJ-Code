#include <stdio.h>

int main(int argc, char *argv[])
{
    int H, W, R, G, B, O;
    while (~scanf("%d%d", &H, &W)) {
        printf("%d %d\n", H, W);
        while (H--) {
            int space = 0;
            int i;
            for (i = 0; i < W; i++) {
                scanf("%d%d%d", &R, &G, &B);
                O = (R+G+B)/3;
                if (!space) {
                    printf("%d", O);
                    space = 1;
                }
                else {
                    printf(" %d", O);
                }
                printf(" %d", O);
                printf(" %d", O);
            }
            putchar(10);
        }
    }
    return 0;
}
