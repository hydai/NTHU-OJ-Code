#include <stdio.h>
#include <stdlib.h>

#define MAX_POW 1000 + 100


int main(int argc, char *argv[])
{
    int times, a, b, A[MAX_POW], B[MAX_POW];
    int i, j;
    scanf("%d", &times);

    while (times > 0) {
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        scanf("%d%d", &a, &b);
        for (i = a; i >= 0; i--) {
            scanf("%d", &A[i]);
        }
        for (i = b; i >= 0; i--) {
            scanf("%d", &B[i]);
        }
        for (i = (a>b)?a:b; i > 0; i--) {
            printf("%d ", A[i]+B[i]);
        }
        printf("%d\n", A[0]+B[0]);

        times--;
    }
    return 0;
}
