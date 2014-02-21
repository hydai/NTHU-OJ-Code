#include <stdio.h>
int main(int argc, char *argv[])
{
    int n, m, i, j, k, x, y, arr[15][15], total = 0, sum = 0;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &arr[i][j]), total+= arr[i][j];
    scanf("%d", &k);
    for (i = 0; i < k; i++) {
        scanf("%d%d", &x, &y);
        sum += arr[x-1][y-1];
    }
    printf("%d %d", sum, total-sum);
    return 0;
}
