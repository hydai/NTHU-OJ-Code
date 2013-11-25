#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int list[100000+100];
int mini(int a, int b) {
    return (a>b)?b:a;
}
int main(int argc, char *argv[])
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int i, min = 1e9, n, sum, tmpSum = 0, st = 0, ed = 0;
        memset(list, 0, sizeof(list));
        scanf("%d%d", &n, &sum);
        for (i = 0; i < n; i++) {
            scanf("%d", &list[i]);
        }
        tmpSum = list[0];
        while (st < n && ed < n) {
            if (tmpSum >= sum) {
                min = mini(min, (st-ed+1));
                tmpSum -= list[ed++];
            }
            else {
                tmpSum += list[++st];
            }
        }
        while (tmpSum >= sum && ed < n) {
            min = mini(min, (st-ed+1));
            tmpSum -= list[ed++];
        }
        if (min == 1e9) {
            min = 0;
        }
        printf("%d\n", min);
    }
    return 0;
}
