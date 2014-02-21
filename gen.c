#include <stdio.h>

int main(int argc, char *argv[])
{
    char str[100];
    while (NULL!=gets(str)) {
        int i;
        printf("puts(\"");
        for (i = 0; i < 80; i++) {
            if (str[i] == '\\') {
                printf("\\\\");
            }
            else {
                putchar(str[i]);
            }
        }
        printf("\");\n");
    }
    return 0;
}
