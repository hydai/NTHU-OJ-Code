#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_LEN 1000+50

int main(int argc, char *argv[])
{
    int str_len, sq, i;
    char tmp_in[MAX_LEN];
    while (~scanf("%s", tmp_in)) {
        if (tmp_in[0]=='0') {
            break;
        }
        
        str_len = strlen(tmp_in);
        if (str_len%2==0) {
            sq = (tmp_in[0]-'0')*10+(tmp_in[1]-'0');
            str_len = (str_len-2)/2;
        }
        else {
            sq = tmp_in[0]-'0';
            str_len = (str_len-1)/2;
        }
        printf("%d", (int)sqrt(sq));
        for (i = 0; i < str_len; i++) {
            putchar('0');
        }
        putchar('\n');

    }
    return 0;
}
