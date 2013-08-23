#include <stdio.h>
#include <string.h>

#define LIMIT 8 /*8 queens*/
#define TRUE 1
#define FALSE 0

int ans[LIMIT], max_value, input[LIMIT][LIMIT], is_visit[3][LIMIT];

void dfs(int time)
{
    int i, j, sum, flag;
    if (time==LIMIT) {
        sum = 0;
        for (i = 0; i < LIMIT; i++) {
            sum+=input[i][ans[i]];
        }
        if (max_value<sum) {
            max_value = sum;
        }
        return;
    }
    else {
        for (i = 0; i < LIMIT; i++) {
            flag = TRUE;
            ans[time] = i;
            for (j = 0; j < time; j++) {
                if (ans[time] == ans[j] || time-ans[time] == j-ans[j] || time+ans[time] == j+ans[j]) {
                    flag = FALSE;break;
                }
            }
            if (flag) {
                dfs(time+1);
            }
        }
    }

}
int main(int argc, char *argv[])
{
    int n, i, j;
    scanf("%d", &n);
    while (n--) {
        for (i = 0; i < LIMIT; i++) {
            for (j = 0; j < LIMIT; j++) {
                scanf("%d", &input[i][j]);
            }
        }
        memset(is_visit, 0, sizeof(is_visit));
        max_value = 0;
        dfs(0);
        printf("%5d\n", max_value);
    }
    return 0;
}
