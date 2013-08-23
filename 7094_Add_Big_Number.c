#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 150

void add(int A[], int B[], int ans[])
{
    int i, carry = 0;
    for (i = 0; i < MAX_LEN; i++) {
        ans[i] += A[i] + B[i];
        if (ans[i]>9) {
            ans[i+1] += ans[i]/10;
            ans[i] %= 10;
        }
    }
}

void sub(int big[], int small[], int ans[])
{
    int i, carry = 0, first;

    for (i = 0; i < MAX_LEN; i++) {
        ans[i] = big[i] - small[i];
        if (ans[i]<0) {
            big[i+1]-=1;
            ans[i]+=10;
        }
    }
}

int main(int argc, char *argv[])
{
    char in_A[MAX_LEN], in_B[MAX_LEN];
    int first, who_bigger, i, A[MAX_LEN], B[MAX_LEN], ans[MAX_LEN], length, A_sign, B_sign, A_len, B_len;

    while (~scanf("%s%s", in_A, in_B)) {
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        memset(ans, 0, sizeof(ans));
        A_sign = 0, B_sign = 0;
        who_bigger = 0;
        /*inverse*/
        if (in_A[0]=='-') {
            A_sign = 1;
        }
        if (in_B[0]=='-') {
            B_sign = 1;
        }

        A_len = strlen(in_A)-A_sign;
        for (i = 0; i < A_len; i++) {
            A[i] = in_A[A_len-i-1+A_sign] - '0';
        }
        B_len = strlen(in_B)-B_sign;
        for (i = 0; i < B_len; i++) {
            B[i] = in_B[B_len-i-1+B_sign] - '0';
        }

        /*special 0 handle*/
        if (A_len == B_len && A_len == 1 && A[0] == 0 && B[0] == 0) {
            printf("0\n");
            continue;
        }

        if (A_sign == B_sign) {
            if (A_sign) {
                printf("-");
            }
            add(A, B, ans);
            first = 1;
            for (i = MAX_LEN-1; i >= 0; i--) {
                if (first && ans[i]==0) {
                    continue;
                }
                else {
                    first = 0;
                }
                printf("%d", ans[i]);
            }
            printf("\n");
            continue;
        }

        /*check who is bigger*/
        for (i = MAX_LEN-1; i >= 0; i--) {
            if (A[i]>B[i]) {
                who_bigger = 1;
                break;
            }
            if (A[i]<B[i]) {
                who_bigger = 2;
                break;
            }
        }

        if (who_bigger == 1) {
            if (A_sign) {
                printf("-");
            }
            sub(A, B, ans);
            first = 1;
            for (i = MAX_LEN-1; i >= 0; i--) {
                if (first && ans[i]==0) {
                    continue;
                }
                else {
                    first = 0;
                }
                printf("%d", ans[i]);
            }
            printf("\n");
        }
        else if (who_bigger == 2) {
            if (B_sign) {
                printf("-");
            }
            sub(B, A, ans);
            first = 1;
            for (i = MAX_LEN-1; i >= 0; i--) {
                if (first && ans[i]==0) {
                    continue;
                }
                else {
                    first = 0;
                }
                printf("%d", ans[i]);
            }
            printf("\n");
        }
        else {
            printf("0\n");
        }
    }
    return 0;
}
