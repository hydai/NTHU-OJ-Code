#include <stdio.h>
#include <stdlib.h>
#include <string.h>


long long dp[30000+100];
int unit[] = {1, 5, 10, 25, 50};
int main(int argc, char *argv[])
{
    int i, j;
    /*memset(dp, 0, sizeof(dp));*/
    dp[0] = 1;
    for (i = 0; i < sizeof(unit)/sizeof(int); i++) {
        for (j = unit[i]; j <= 30000; j++) {
            dp[j] += dp[j-unit[i]];
        }
    }
    while (~scanf("%d", &i)) {
        if (dp[i] == 1) {
            printf("There is only 1 way to produce %d cents change.\n", i);
        }
        else {
            printf("There are %lld ways to produce %d cents change.\n", dp[i], i);
        }
    }
    return 0;
}
