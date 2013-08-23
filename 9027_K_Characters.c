#include <stdio.h>
#include <string.h>

#define MAX 105

char check[MAX], ans[15], last[15];
short vit[MAX];
int limit, max_l, check_l;
void dfs(int index, int time)
{
    int i;
    char tmp[15] = {};

    if (index>max_l || vit[index] || time > limit) {
        return;
    }
    if (time==limit && (strcmp(last, ans)!=0)) {
        for (i = 0; i < time; i++) {
            putchar(ans[i]);
        }
        putchar(10);
        ans[time--] = '\0';
        strcpy(last, ans);
        return;
    }
    ans[time] = check[index];
    vit[index] = 1;
    dfs(index+1, time+1);
    vit[index] = 0;
    dfs(index+1, time);
}


int main(int argc, char *argv[])
{
    char tmp_in[MAX], isVisit[256];
    int i, n, len, check_ct;
    scanf("%d", &n);

    while (n--) {
        memset(isVisit, 0, sizeof(isVisit));
        memset(vit, 0, sizeof(vit));
        memset(check, 0, sizeof(check));
        check_ct = 0;
        scanf("%s%d", tmp_in, &limit);
        len = strlen(tmp_in);
        for (i = 0; i < len; i++) {
            isVisit[tmp_in[i]]++;
        }
        for (i = 'A'; i <= 'K'; i++) {
            if (isVisit[i]>limit) {
                isVisit[i] = limit;
            }
            while (isVisit[i]--) {
                check[check_ct++] = i;
            }
        }
        max_l = check_ct;
        dfs(0, 0);
    }
    return 0;
}
