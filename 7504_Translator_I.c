#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1500

int main(int argc, char *argv[])
{
    char input[MAX_LEN], tmp_ch;
    int list[1002][MAX_LEN]={}, ans[MAX_LEN], tmp[MAX_LEN];
    int i, j, length, first, tmp_num;

    /* build list */
    list[0][0] = 1;
    for (i = 1; i < 1002; i++) {
        for (j = 0; j < MAX_LEN; j++) {
            list[i][j] = list[i-1][j]*2;
        }
        for (j = 0; j < MAX_LEN; j++) {
            list[i][j+1] += list[i][j]/10;
            list[i][j] %= 10;
        }
    }
    while (NULL!=gets(input)) {
        memset(ans, 0, sizeof(ans));
        first = 0;
        length = strlen(input);
        for (i = 0; i < length/2; i++) {
            tmp_ch = input[i], input[i] = input[length-i-1], input[length-i-1] = tmp_ch;
        }
        for (i = 0; i < length; i++) {
            memset(tmp, 0, sizeof(tmp));
            tmp_num = input[i]-'0';
            for (j = 0; j < MAX_LEN; j++) {
                tmp[j] = list[i][j]*tmp_num;
            }
            for (j = 0; j < MAX_LEN; j++) {
                tmp[j+1] += tmp[j]/10;
                tmp[j] %= 10;
            }
            for (j = 0; j < MAX_LEN; j++) {
                ans[j]+=tmp[j];
            }
        }

        for (i = 0; i < MAX_LEN; i++) {
            ans[i+1] += ans[i]/10;
            ans[i] %= 10;
        }
        for (i = MAX_LEN-1; i >= 0; i--) {
            if (ans[i]==0 && first==0) {
                continue;
            }
            else {
                first = 1;
            }
            printf("%d", ans[i]);
        }
        if (first==0) {
            printf("0");
        }
        printf("\n");
    }
    return 0;
}
