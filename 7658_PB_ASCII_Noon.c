#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LLI long long int
LLI gcd(LLI a, LLI b) {
    while ((a!=0) && (b!=0) && (a%=b) && (b%=a));
    return a+b;
}

LLI parse(int digit) {
    int i, j, k;
    LLI ans = 0;
    char str[3][60];
    for (i = 0; i < 3; i++) {
        gets(str[i]);
    }
    for (j = 0; j < digit; j++) {
        for (k = 1; k <= 3; k++) {
            for (i = 0; i < 3; i++) {
                if (str[i][k+j*4] != ' ') {
                    ans = ans*10 + str[i][k+j*4] - '0';
                }
            }
        }
    }
    gets(str[0]);
    return ans;
}

void println(int isBound, int len) {
    if (isBound) {
        putchar('+');
        while (len--) {
            printf("---+");
        }
    }
    else {
        putchar('|');
        while (len--) {
            printf("   |");
        }
    }
    putchar(10);
}

void print(LLI ans) {
    char output[50];
    int len, i;
    sprintf(output, "%lld", ans);
    len = strlen(output);
    println(1, len);
    println(0, len);
    for (i = 0; i < len; i++) {
        printf("| %c ", output[i]);
    }
    printf("|\n");
    println(0, len);
    println(1, len);
}
int main(int argc, char *argv[])
{
    char str[60];
    int i, j, k;
    int space = 0;
    while (gets(str) != NULL) {
        LLI a, b, ans;
        int digit = (strlen(str) - 1)/4;
        a = parse(digit);
        gets(str);
        digit = (strlen(str) - 1)/4;
        b = parse(digit);
        ans = gcd(a, b);
        if (space++) {
            putchar(10);
        }
        print(ans);
    }
    return 0;
}
