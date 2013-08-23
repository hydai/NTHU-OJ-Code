#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10000


int main(int argc, char *argv[])
{
    char str[MAX_LEN]={};
    int length, i, odd, even, num[MAX_LEN]={};

    while (~scanf("%s", str)) {
        if (str[0]=='0' && strlen(str)==1) {
            break;
        }
        odd = 0;
        even = 0;
        length = strlen(str);
        for (i = 0; i < length; i++) {
            num[i] = str[length-i-1]-'0';
            if ((i+1)%2==0) {
                even += num[i];
            }
            else {
                odd += num[i];
            }
        }
        if ((odd-even)%11==0) {
            printf("%s is a multiple of 11.\n", str);
        }
        else {
            printf("%s is not a multiple of 11.\n", str);
        }
        memset(str, 0, MAX_LEN);
        memset(num, 0, MAX_LEN);
    }
    return 0;
}
