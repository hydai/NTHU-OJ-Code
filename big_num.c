#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100000

char input[MAX_LENGTH];
int ans[MAX_LENGTH];

void to_int()
{
    int i;
    for (i = strlen(input); i > 0; i--) {
        ans[i-1] = input[strlen(input)-i] - '0';
    }
}

void pr_int()
{
    int i, flag = 1;
    for (i = MAX_LENGTH-1; i >= 0; i--) {
        if (ans[i] == 0 && flag) {
            continue;
        }
        else {
            flag = 0;
        }
        if (!flag) {
            printf("%d", ans[i]);
        }
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    while (~scanf("%s", input)) {
        memset(ans, 0, sizeof(ans));
        to_int();
        pr_int();
    }
    return 0;
}
