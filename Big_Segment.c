#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, arr[100000+50][2], l, r;

int main(int argc, char *argv[])
{
    while (~scanf("%d", &n)) {
        int i, flag = 0;
        l = 10e9+1;
        r = 0;
        for (i = 0; i < n; i++) {
            scanf("%d%d", &arr[i][0], &arr[i][1]);
            if (arr[i][0] < l) {
                l = arr[i][0];
            }
            if (arr[i][1] > r) {
                r = arr[i][1];
            }
        }
        i = 0;
        while (i < n && (!flag)) {
            if (arr[i][0] <= l && arr[i][1] >= r) {
                flag = 1;
                printf("%d\n", i+1);
            }
            i++;
        }
        if (!flag) {
            printf("-1\n");
        }

    }
    return 0;
}
