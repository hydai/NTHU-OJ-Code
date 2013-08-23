#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_MAX 1005

char g_A[INPUT_MAX], g_B[INPUT_MAX], g_OUT[INPUT_MAX];
int carry_count;

void get_num(char A[], char B[])
{
    int length_A, length_B;
    int i;
    length_A = strlen(A);
    length_B = strlen(B);

    carry_count = 0;
    for (i = 0; i < INPUT_MAX; i++) {
        g_A[i] = 0;
        g_B[i] = 0;
        g_OUT[i] = 0;
    }
    for (i = 0; i < length_A; i++) {
        g_A[length_A - i - 1] = A[i] - '0';
    }
    for (i = 0; i < length_B; i++) {
        g_B[length_B - i - 1] = B[i] - '0';
    }
    for (i = 0; i < ((length_A > length_B)?length_A:length_B); i++) {
        g_OUT[i] = g_A[i] + g_B[i];
    }

    for (i = 0; i < ((length_A > length_B)?length_A:length_B); i++) {
        if (g_OUT[i] >= 10) {
            carry_count++;
            g_OUT[i+1] += g_OUT[i] / 10;
            g_OUT[i] %= 10;
        }
    }
    printf("%d\n", carry_count);
}

int main(int argc, const char *argv[])
{
    char A[INPUT_MAX], B[INPUT_MAX];
    while (~scanf("%s%s", A, B)) {
        get_num(A, B);
    }
    return 0;
}
