#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int n, a, b, stack[1050], top, len;
    char oper[100];
    scanf("%d", &n);
    while (n--) {
        int i;
        memset(stack, 0, sizeof(stack));
        top = 0;
        scanf("%d", &len);
        for (i = 0; i<len;i++) {
            scanf("%s", oper);
            if (strlen(oper)==1 && oper[0]=='-') {
                a = stack[--top];
                b = stack[--top];
                stack[top++] = b-a;
            }
            else if (strlen(oper)==1 && oper[0]=='+') {
                a = stack[--top];
                b = stack[--top];
                stack[top++] = b+a;
            }
            else {
                if (oper[0]=='-') {
                    int j = 1, tmp = 0;
                    while (oper[j]!='\0') {
                        tmp = tmp *10 + (oper[j++]-'0');
                    }
                    stack[top++] = -tmp;
                }
                else {
                    int j = 0, tmp = 0;
                    while (oper[j]!='\0') {
                        tmp = tmp *10 + (oper[j++]-'0');
                    }
                    stack[top++] = tmp;
                }
            }
        }
        printf("%d\n", stack[0]);
    }
    return 0;
}
