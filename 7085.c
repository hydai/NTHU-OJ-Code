#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10000

char string[MAX_LEN];

int main(int argc, char *argv[])
{
    char tmp_ch;
    int nl_flag = 0;

    while (~scanf("%[A-Z,a-z][^\n]", string)) {
        if (nl_flag) {
            printf("\n");
            nl_flag = 0;
        }
        else if (string[0]=='a' || string[0]=='e' || string[0]=='i' || string[0]=='o' || string[0]=='u' || string[0]=='A' || string[0]=='O' || string[0]=='E' || string[0]=='I' || string[0]=='U') {
            printf("%say", string);
        }
        else {
            printf("%s%cay", string+1, string[0]);
        }
        tmp_ch = getchar();
        if (tmp_ch == '\n') {
            nl_flag = 1;
        }
        else {
            putchar(tmp_ch);
        }
        printf("3\n");
    }
    return 0;
}
