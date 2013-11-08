#include <stdio.h>
#include <string.h>

#define LEN 1050
#define RIGHT 1
#define ERROR 0
int main(int argc, char *argv[])
{
    int i, N, stack_index, len, flag = RIGHT;
    char str[LEN], stack[LEN];
    scanf("%d", &N);
    getchar();
    while (N--) {
        fgets(str, LEN, stdin);
        flag = RIGHT;
        stack_index = 0;

        if (str[0] == '\n') {
            printf("Yes\n");
            continue;
        }
        len = strlen(str);
        for (i = 0; i < len; i++) {
            if (str[i] == '{' || str[i] == '[' || str[i] == '(' || str[i] == '<') {
                stack[stack_index++] = str[i];
            }
            else if (str[i] == '}') {
                if (stack_index > 0 && stack[stack_index-1] == '{') {
                    stack_index--;
                }
                else {
                    flag = ERROR;
                    break;
                }
            }
            else if (str[i] == ']') {
                if (stack_index > 0 && stack[stack_index-1] == '[') {
                    stack_index--;
                }
                else {
                    flag = ERROR;
                    break;
                }
            }
            else if (str[i] == ')') {
                if (stack_index > 0 && stack[stack_index-1] == '(') {
                    stack_index--;
                }
                else {
                    flag = ERROR;
                    break;
                }
            }
            else if (str[i] == '>') {
                if (stack_index > 0 && stack[stack_index-1] == '<') {
                    stack_index--;
                }
                else {
                    flag = ERROR;
                    break;
                }
            }
        }
        if (stack_index != 0) {
            flag = ERROR;
        }
        if (flag == RIGHT) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }

    }

return 0;
}
