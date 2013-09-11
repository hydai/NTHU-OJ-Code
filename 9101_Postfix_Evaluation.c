#include <stdio.h>
#include <string.h>

int Stack[6000];
int StackIndex;

int main(int argc, char *argv[])
{
    int N, CMD, A, B, count = 1;
    char buffer[50];
    scanf("%d", &N);
    while (N--) {
        StackIndex = 0;
        scanf("%d", &CMD);
        while (CMD--) {
            scanf("%s", buffer);
            if (buffer[0] == '+') {
                B = Stack[StackIndex-1];
                A = Stack[StackIndex-2];
                StackIndex -= 2;
                Stack[StackIndex++] = A+B;
            }
            else if (buffer[0] == '-') {
                B = Stack[StackIndex-1];
                A = Stack[StackIndex-2];
                StackIndex -= 2;
                Stack[StackIndex++] = A-B;
            }
            else if (buffer[0] == '*') {
                B = Stack[StackIndex-1];
                A = Stack[StackIndex-2];
                StackIndex -= 2;
                Stack[StackIndex++] = A*B;
            }
            else if (buffer[0] == '/') {
                B = Stack[StackIndex-1];
                A = Stack[StackIndex-2];
                StackIndex -= 2;
                Stack[StackIndex++] = A/B;
            }
            else {
                int tmp = 0;
                int len = strlen(buffer);
                int i, P = 1;
                for (i = len-1; i >= 0; i--) {
                    tmp += (buffer[i]-'0')*P;
                    P *= 10;
                }
                Stack[StackIndex++] = tmp;
            }
        }
        printf("Case %d: %d\n", count++, Stack[0]);
    }
    return 0;
}
