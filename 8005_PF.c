#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char str[100];
    int i, len;
    while (gets(str) != NULL) {
        len = strlen(str);
        if (len%2 == 1) {
            for (i = len-1; i >= 0; i--) {
                putchar(str[i]);
            }
        }
        else {
            for (i = 0; i < len; i++) {
                putchar(str[i]);
            }
        }
        putchar(10);
    }
    return 0;
}
