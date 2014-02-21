#include <stdio.h>
#define SIZE 105
int main(int argc, char *argv[])
{
    long long int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
    int m, n, p, t;
    int i, j, k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &m, &n, &p);
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                scanf("%lld", &A[i][j]);
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < p; j++) {
                scanf("%lld", &B[i][j]);
            }
        }
        for (i = 0; i < m; i++) {
            for (j = 0; j < p; j++) {
                C[i][j] = 0;
                for (k = 0; k < n; k++) {
                    C[i][j] += A[i][k]*B[k][j];
                }
            }
        }
        for (i = 0; i < m; i++) {
            printf("%lld", C[i][0]);
            for (j = 1; j < p; j++) {
                printf(" %lld", C[i][j]);
            }
            putchar(10);
        }
        putchar(10);
    }
    return 0;
}
