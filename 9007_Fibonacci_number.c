#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100000

int a[MAX_LENGTH], b[MAX_LENGTH];

void pr_int(int *ans)
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

void fibonacci(int n)
{
    for (i = 0; i < 10; i++) {
        /* code */
    }
}

int main(int argc, char *argv[])
{
    int n;
    while (~scanf("%d", &n)) {
        memset(ans, 0, sizeof(ans));
        fibonacci(n);
        pr_int();
    }
    return 0;
}
