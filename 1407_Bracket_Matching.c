#include <stdio.h>

int main(int argc, char *argv[])
{
    int stack[40010], space = 0, count = 0, index = 0;
    char tmp;
    while ((tmp = getchar()) != EOF) {
        count++;
        if (tmp == '\n') {
            count = 0;
            index = 0;
            space = 0;
            putchar(10);
        }
        else if (tmp == '('){
            stack[index++] = count;
        }
        else {
            if (space++) {
                putchar(32);
            }
            printf("%d", stack[--index]);
        }
    }
    return 0;
}
