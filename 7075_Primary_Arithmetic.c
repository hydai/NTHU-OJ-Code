#include <stdio.h>
#include <stdlib.h>

int a, b, i, carry_in;
int A[15], B[15];
int main(int argc, char *argv[])
{
    while ( scanf("%d%d", &a, &b) ) {
        if (a == b && a == 0) {
            break;
        }
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        i = 0;
        while (a != 0) {
            A[i] = a%10;
            a /= 10;
            i++;
        }
        i = 0;
        while (b != 0) {
            B[i] = b%10;
            b /= 10;
            i++;
        }

        carry_in = 0;
        for (i = 0; i < 10; i++) {
            A[i]+=B[i];
            if (A[i] > 9) {
                A[i]%=10;
                A[i+1]++;
                carry_in++;
            }
        }

        if (carry_in == 0) {
            printf("No carry operation.\n");
        }
        else if (carry_in == 1) {
            printf("1 carry operation.\n");
        }
        else {
            printf("%d carry operations.\n", carry_in);
        }
    }
    return 0;
}
