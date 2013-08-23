#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 10000000

char string[MAX_LEN];

int main(int argc, char *argv[])
{
    char tmp_ch;
    int length, i, head, flag = 0;

    while (NULL!=gets(string)) {
        length = strlen(string);

        for (i = 0; i < length; i++) {
            if (isalpha(string[i])) {
                if (string[i]=='a' || string[i]=='e' || string[i]=='i' || string[i]=='o' || string[i]=='u' || string[i]=='A' || string[i]=='O' || string[i]=='E' || string[i]=='I' || string[i]=='U') {
                    printf("%c", string[i]);
                    flag = 1;
                }
                else {
                    flag = 0;
                }
                head = i;
                i++;
                while (isalpha(string[i])) {
                    printf("%c", string[i++]);
                }
                if (!flag) {
                    printf("%c", string[head]);
                }

                printf("ay");
            }
            printf("%c", string[i]);
        }
        printf("\n");
    }
    return 0;
}
