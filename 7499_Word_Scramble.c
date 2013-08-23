#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char string[100000];

int main(int argc, char *argv[])
{
    int length;
    int i;
    while (~scanf("%s", string)) {
        length = strlen(string);
        for (i = length-1; i >= 0; i--) {
            putchar(string[i]);
        }
        if (getchar()=='\n') {
            putchar('\n');
        }
        else {
            putchar(' ');
        }
    }
    return 0;
}
