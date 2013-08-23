#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 140

int main(int argc, char *argv[])
{
    char string[MAX_LEN];
    int put_times, i, length;
    
    
    while (NULL!=fgets(string, MAX_LEN, stdin)) {
        length = strlen(string);
        put_times = 0;

        for (i = 0; i < length; i++) {
            if (isdigit(string[i])) {
                put_times += string[i]-'0';
            }
            else if (string[i]=='!') {
                putchar('\n');
            }
            else if (string[i]=='\n'){
                putchar('\n');
            }
            else {
                if (string[i]=='b') {
                    while (put_times--) {
                        putchar(' ');
                    }
                    put_times++;
                }
                else {
                    while (put_times--) {
                        putchar(string[i]);
                    }
                    put_times++;
                }
            }
        }
    }
    return 0;
}
