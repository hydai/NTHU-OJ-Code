#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    char stack[200], input[200], check;
    int times, is_true, i, stack_entry, stack_top, length;

    scanf("%d", &times);
    getchar();
    while (times--) {
        gets(input);
        memset(stack, 0, sizeof(stack)), stack_entry = 0, stack_top = 0;
        length = strlen(input);
        if (length == 0) {
            printf("Yes\n");
            continue;
        }
        is_true = 1;
        for (i = 0; i < length; i++) {
            if (input[i]=='(' || input[i]=='[')
            {
                stack[stack_top++] = input[i];
            }
            else if (input[i]==')' || input[i]==']') {
                check = stack[--stack_top];
                if (check=='['&&input[i]==']') {}
                else if (check=='('&&input[i]==')') {}
                else
                {
                    is_true = 0;
                    break;
                }
            }
        }
        if (stack_top!=0) {
            is_true = 0;
        }
        if (is_true) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }

    return 0;
}
