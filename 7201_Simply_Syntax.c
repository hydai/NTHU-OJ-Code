/****************************************************************************
 * 本題想法->
 * 剛好最近資料結構教到ㄡ前序中序後序的問題
 * 這題的想法很接近判斷是否為前序表示式
 ****************************************************************************/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 300

char stack[MAX_LEN];
int stack_size, stack_top;

int main(int argc, char *argv[])
{
    char tmp_in[MAX_LEN], tmp_ch;
    int length, i, flag;

    while (~scanf("%s", tmp_in)) {
        stack_top = -1;
        stack_size = 0;
        flag = 1;
        length = strlen(tmp_in);
        for (i = length-1; i >= 0; i--) {
            /* common digits */
            if (tmp_in[i]>='p'&&tmp_in[i]<='z') {
                stack[++stack_top] = tmp_in[i];
                stack_size++;
            }
            else if (tmp_in[i]=='N') {
                /* negation */
                if (stack_size==0) {
                    flag = 0;
                    break;
                }
                stack[stack_top] += tmp_in[i];
            }
            else if (tmp_in[i]=='C'||tmp_in[i]=='D'||tmp_in[i]=='E'||tmp_in[i]=='I') {
                /* operator */
                if (stack_size==0) {
                    flag = 0;
                    break;
                }
                tmp_ch = stack[stack_top--], stack_size--;
                if (stack_size==0) {
                    flag = 0;
                    break;
                }
                stack[stack_top] += tmp_ch;
            }
            else {
                flag = 0;
                break;
            }
        }
        if (stack_size!=1) {
            flag = 0;
        }
        printf("%s\n", (flag)?"YES":"NO");
    }
    return 0;
}
