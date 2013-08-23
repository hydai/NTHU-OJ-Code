#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GCD(int a, int b)
{
    if(b)
        while ((a%=b)&&(b%=a)) {
            /* do no thing */
        }
    return a+b;
}

int main(int argc, char *argv[])
{
    int n, tmp_in, total_in, ans_sign, a, A_length, B_length, C_length, MAX_len;
    int i, times, total_len, length, A[10], B[10], C[10], gcd;
    times = 0;
    while (~scanf("%d", &n)) {
        if (n==0) {
            break;
        }
        times++;
        ans_sign = 0;
        total_in = 0;
        printf("Case %d:\n", times);

        for (i = 0; i < n; i++) {
            scanf("%d", &tmp_in);
            total_in+=tmp_in;
        }
        if (total_in<0) {
            ans_sign = 1, total_in = -total_in;
        }
        /* integer out first */
        if (total_in%n==0) {
            if (ans_sign) {
                printf("- %d\n", total_in/n);
            }
            else {
                printf("%d\n", total_in/n);
            }
            continue;
        }
        /* other */
        a = total_in/n;
        total_in%=n;
        A_length = B_length = C_length = MAX_len = 0;
        gcd = GCD(total_in, n);
        total_in/=gcd, n/=gcd;
        while (a) {
            A[A_length++] = a%10;
            a/=10;
        }
        while (total_in) {
            B[B_length++] = total_in%10;
            total_in/=10;
        }
        while (n) {
            C[C_length++] = n%10;
            n/=10;
        }
        MAX_len = (B_length>C_length)?B_length:C_length;
        if (ans_sign) {
            MAX_len+=2;
        }
        MAX_len+=A_length;
        for (i = 0; i < MAX_len-B_length; i++) {
            putchar(' ');
        }
        for (i = B_length-1; i >= 0; i--) {
            putchar(B[i]+'0');
        }
        putchar('\n');
        if (ans_sign) {
            printf("- ");
            MAX_len-=2;
        }
        for (i = A_length-1; i >= 0; i--) {
            putchar(A[i]+'0');
        }
        for (i = 0; i < ((B_length>C_length)?B_length:C_length); i++) {
            putchar('-');
        }
        if (ans_sign) {
            MAX_len+=2;
        }
        putchar('\n');
        for (i = 0; i < MAX_len-C_length; i++) {
            putchar(' ');
        }
        for (i = C_length-1; i >= 0; i--) {
            putchar(C[i]+'0');
        }
        putchar('\n');
    }
    return 0;
}
