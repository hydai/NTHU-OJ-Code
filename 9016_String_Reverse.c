#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000000+10

char string[MAX_LEN];

int main(int argc, char *argv[])
{
    int length, i;

    while (~scanf("%s", string)) {
        length = strlen(string);
        for (i = length-1; i >= 0; i--) {
            printf("%c", string[i]);
        }
        printf("\n");
        /*memset(string, 0, MAX_LEN*sizeof(char));*/
    }
    return 0;
}
