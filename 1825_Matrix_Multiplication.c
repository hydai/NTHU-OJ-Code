#include <stdio.h>

#define SIZE 55

int main(int argc, char *argv[])
{
    int A[SIZE][SIZE], B[SIZE][SIZE];
    int a, b, c, i, j, k;
    while (~scanf("%d%d%d", &a, &b, &c)) {
        for (i = 0; i < a; i++) {
            for (j = 0; j < b; j++)
                scanf("%d", &A[i][j]);
        }
        for (i = 0; i < b; i++) {
            for (j = 0; j < c; j++)
                scanf("%d", &B[i][j]);
        }
        for (i = 0; i < a; i++) {
            int tmp = 0;
            for (k = 0; k < b; k++) {
                tmp += A[i][k]*B[k][0];
            }
            printf("%d", tmp);
            for (j = 1; j < c; j++) {
                tmp = 0;
                for (k = 0; k < b; k++) {
                    tmp += A[i][k]*B[k][j];
                }
                printf(" %d", tmp);
            }
            putchar(10);
        }
    }
    return 0;
}
