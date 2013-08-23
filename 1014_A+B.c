#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{
    int t, a, b, A[5], A_MAX, B[5], B_MAX, sum, i;
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));

    scanf("%d", &t);
    while (t>0) {
        scanf("%d%d", &a, &b);
        sum = A_MAX = B_MAX = 0;
        for (i = 0; i < 5; i++) {
            A[i] = a%10;
            B[i] = b%10;
            if (A[i] > A_MAX) {
                A_MAX = A[i];
            }
            if (B[i] > B_MAX) {
                B_MAX = B[i];
            }
            a /= 10;
            b /= 10;
        }

        A_MAX++;
        B_MAX++;
        for (i = 0; i < 5; i++) {
            sum += (int)pow(A_MAX, i)*A[i] + (int)pow(B_MAX, i)*B[i];
        }
        printf("%d\n", sum);
        t--;
    }
    return 0;
}
