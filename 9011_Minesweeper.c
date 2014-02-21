#include <stdio.h>
#include <stdlib.h>

#define MAX_SCALE 100 + 10

void add(int (*ans)[MAX_SCALE], int i, int j)
{
    ans[i-1][j-1]++;
    ans[i-1][j]++;
    ans[i-1][j+1]++;
    ans[i][j-1]++;
    ans[i][j+1]++;
    ans[i+1][j-1]++;
    ans[i+1][j]++;
    ans[i+1][j+1]++;
}

int main(int argc, char *argv[])
{
    int n, input[MAX_SCALE][MAX_SCALE];
    int i, j, tmp;
    while (EOF!=scanf("%d", &n)) {
        memset(input, 0, sizeof(input));
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                scanf("%d", &tmp);
                if (tmp) {
                    add(input, i, j);
                }
            }
        }
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n-1; j++) {
                printf("%d ", input[i][j]);
            }
            printf("%d\n", input[i][j]);
        }
    }
    return 0;
}
