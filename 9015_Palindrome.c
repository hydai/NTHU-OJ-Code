#include <stdio.h>
#include <string.h>

#define LEN 100000+100
#define RIGHT 1
#define ERROR 0
char str[LEN];

int main(int argc, char *argv[])
{
    while (gets(str) != NULL) {
        int len = strlen(str);
        int flag = RIGHT;
        int i;
        for (i = 0; i < len/2; i++) {
            if (str[i] != str[len-i-1]) {
                flag = ERROR;
                break;
            }
        }
        if (flag) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}
