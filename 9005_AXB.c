#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 250

int main(int argc, char *argv[])
{
    char in_A[MAX_LEN], in_B[MAX_LEN];
    int A[MAX_LEN], B[MAX_LEN], C[MAX_LEN], i, j, first, A_len, B_len;

    while (~scanf("%s%s", in_A, in_B)) {
        memset(A, 0, sizeof(A)), memset(B, 0, sizeof(B)), memset(C, 0, sizeof(C));
        A_len = strlen(in_A);B_len = strlen(in_B), first = 1;
        for (i = 0; i < A_len; i++) { A[i] = in_A[A_len-i-1]-'0'; }
        for (i = 0; i < B_len; i++) { B[i] = in_B[B_len-i-1]-'0'; }
        for (i = 0; i < A_len; i++) {
            for (j = 0; j < B_len; j++) {
                C[i+j] += A[i]*B[j];
            }
        }
        for (i = 0; i < A_len+B_len; i++) {
            C[i+1] += C[i]/10;
            C[i] %= 10;
        }
        for (i = MAX_LEN-1; i >= 0; i--) {
            if (C[i]==0&&first) {
                continue;
            }
            else {
                first = 0;
            }
            putchar(C[i]+'0');
        }
        putchar('\n');
    }
    return 0;
}
