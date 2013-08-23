#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100000+10

char string[MAX_LEN];

int main(int argc, char *argv[])
{
    int flag, length, i;
    while (~scanf("%s", string)) {
        flag = 0;
        length = strlen(string);
        for (i = 0; i <= length/2; i++) {
            if (string[i]!=string[length-i-1]) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            printf("No\n");
        }
        else {
            printf("Yes\n");
        }
    }
    return 0;
}
