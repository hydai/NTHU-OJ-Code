#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGIT 110

typedef struct {
    short sign;
    short value[MAX_DIGIT];
} number;

void to_int(char tmp_in[], number *input)
{
    int i, length = strlen(tmp_in);
    if (tmp_in[0]=='-') {
        input->sign = 1;
        length--;
        for (i = 0; i < length; i++) {
            input->value[i] = tmp_in[length-i] - '0';
        }
    }
    else {
        input->sign = 0;
        for (i = 0; i < length; i++) {
            input->value[i] = tmp_in[length-i-1] - '0';
        }
    }
}

void pr_int(number input)
{
    int i;
    if (input.sign == 1) {
        printf("-");
    }

    for (i = MAX_DIGIT-1; i > 0; i--) {
        if (input.value[i]==0) {
            continue;
        }
        else {
            break;
        }
    }
    for (; i >= 0; i--) {
        printf("%d", input.value[i]);
    }
    printf("\n");
}

int compare(number *a, number *b)
{
    int i;
    if (a->sign == 1 && b->sign == 0) {
        return -1;
    }
    else if (a->sign == 0 && b->sign == 1) {
        return 1;
    }
    else {
        if (a->sign == 1) {
            for (i = MAX_DIGIT-1; i >= 0; i--) {
                if (a->value[i]>b->value[i]) {
                    return -1;
                }
                else if (a->value[i]<b->value[i]) {
                    return 1;
                }
                else {
                    continue;
                }
            }
        }
        else {
            for (i = MAX_DIGIT-1; i >= 0; i--) {
                if (a->value[i]>b->value[i]) {
                    return 1;
                }
                else if (a->value[i]<b->value[i]) {
                    return -1;
                }
                else {
                    continue;
                }
            }
        }
    }

    return 0;
}
int main(int argc, char *argv[])
{
    number input[100010];
    char tmp_in[MAX_DIGIT];
    int n, i;
    while (~scanf("%d", &n)) {
        memset(input, 0, sizeof(input));
        i = n;
        while (i>0) {
            scanf("%s", tmp_in);
            to_int(tmp_in, &input[n-i]);
        }
        qsort(input, n, sizeof(number), compare);
        i = n;
        while (i>0) {
            pr_int(input[n-i]);
            i--;
        }
    }
    return 0;
}
