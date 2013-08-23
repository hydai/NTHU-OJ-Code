#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1050

int main(int argc, char *argv[])
{
    int flag, initial, check[MAX_LEN], stack[MAX_LEN], stack_top, n, tmp_int, i, check_len;
    char tmp_in[MAX_LEN*10], tmp_ch;
    while (~scanf("%d", &n)&&n) {
        while(scanf("%d", &tmp_int)&&tmp_int!=0)
        {
            i = 0;
            flag = 1;
            while (getchar()!='\n') {
                check[i++] = tmp_int;
                scanf("%d", &tmp_int);
            }
            check[i++] = tmp_int;
            /* ^----- 補上最後一個 */
            check_len = i;
            initial = 1;
            i = 0;
            stack_top = 0;

            while (i<check_len) {
                if (initial==check[i]) {
                    /* 隊列頭剛好是答案 */
                    initial++;
                    i++;
                }
                else if (stack_top&&stack[stack_top]==check[i]) {
                    /* 堆疊頭是答案 */
                    stack_top--;
                    i++;
                }
                else if (initial<n) {
                    /* 都不是答案，塞進去堆疊 */
                    stack[++stack_top] = initial;
                    initial++;
                }
                else {
                    /* 錯誤 */
                    flag = 0;
                    break;
                }
            }

            printf("%s\n", (flag)?"Yes":"No");
        
        }
        putchar('\n');
    }
    return 0;
}
