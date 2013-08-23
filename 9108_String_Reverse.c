#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10000000+10

int main(int argc, char *argv[])
{
    char *string;
    int length, i;
    string = (char*)malloc(MAX_LEN*sizeof(char));

    while (~scanf("%s", string)) {
        length = strlen(string);
        for (i = length-1; i >= 0; i--) {
            putchar(string[i]);
        }
        putchar('\n');
        /*memset(string, 0, MAX_LEN*sizeof(char));*/
    }
    return 0;
}
