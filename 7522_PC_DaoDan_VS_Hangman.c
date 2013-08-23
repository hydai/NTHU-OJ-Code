#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY 0
#define ERROR -1
#define CORRECT 999

int main(int argc, char *argv[])
{
    int n, ans_len, gauss_len, error_time, flag, i, check[128];
    char ans[150], gauss[150];
    while (~scanf("%d", &n) && n != -1) {
        printf("Round %d\n", n);
        scanf("%s%s", ans, gauss);
        memset(check, 0, sizeof(check));
        error_time = 0;
        flag = 0;
        ans_len = strlen(ans);
        gauss_len = strlen(gauss);
        for (i = 0; i < ans_len; i++) {
            check[ans[i]]++;
        }

        for (i = 0; i < gauss_len; i++) {
            if (check[gauss[i]] == EMPTY) { 
                /* Error gauss */
                check[gauss[i]] = ERROR;
                error_time++;
                if (error_time == 7) {
                    flag = -1;
                    break;
                }
            }
            else if (check[gauss[i]] > EMPTY && check[gauss[i]] != CORRECT) {
                /* Correct gauss */
                ans_len -= check[gauss[i]];
                check[gauss[i]] = CORRECT;
                if (ans_len == 0) {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 1) {
            printf("You win.\n");
        }
        else if (flag == -1) {
            printf("You lose.\n");
        }
        else {
            printf("You chickened out.\n");
        }

    }
    return 0;
}
