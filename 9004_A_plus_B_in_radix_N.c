#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 500

int getValue(char input) {
    if (input <= '9') {
        return input-'0';
    }
    else {
        return input-'A'+10;
    }
}

char returnValue(int input) {
    if (input <= 9) {
        return input+'0';
    }
    else {
        return input-10+'A';
    }
}

int main(int argc, char *argv[])
{
    int i, N, lenA, lenB, len, ZERO;
    char A[LEN], B[LEN], ANS[LEN];
    int NA[LEN], NB[LEN];

    while (~scanf("%d%s%s", &N, A, B)) {
        memset(ANS, 0, sizeof(ANS));
        memset(NA, 0, sizeof(NA));
        memset(NB, 0, sizeof(NB));
        lenA = strlen(A);
        for (i = 0; i < lenA; i++) {
            NA[i] = getValue(A[lenA-i-1]);
        }
        lenB = strlen(B);
        for (i = 0; i < lenB; i++) {
            NB[i] = getValue(B[lenB-i-1]);
        }
        len = ((lenA > lenB)?lenA:lenB);
        for (i = 0; i < len; i++) {
            NA[i] += NB[i];
            NA[i+1] += NA[i]/N;
            NA[i] %= N;
        }
        
        for (i = 0; i < 205; i++) {
            ANS[i] = returnValue(NA[i]);
        }
        ZERO = 0;

        for (i = 204; i >= 0; i--) {
            if (!ZERO && ANS[i] == '0') {
                continue;
            }
            else {
                ZERO = 1;
            }
            putchar(ANS[i]);
        }
        putchar(10);
    }
    return 0;
}
