#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int all, times, a, b, i, sum;

    scanf("%d", &all);
    times = all;
    while (times > 0) {
        scanf("%d%d", &a, &b);
        if (a%2 == 0) {
            a+=1;
        }

        sum = 0;
        for (i = a; i <= b; i+=2) {
            sum += i;
        }
        times--;
        printf("Case %d: %d\n", all-times, sum);
    }
    return 0;
}
