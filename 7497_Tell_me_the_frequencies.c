#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000+30

int main(int argc, char *argv[])
{
    char string[MAX_LEN];
    int ch[140] = {0}, first;
    int value[140][2], len, i, j, tmp;

    first = 0;
    while (NULL!=gets(string)) {
        memset(ch, 0, sizeof(ch));
        memset(value, 0, sizeof(value));

        len = strlen(string);
        for (i = 0; i < len; i++) {
            ch[string[i]]++;
        }
        
        len = 0;
        for (i = 0; i < 140; i++) {
            if (ch[i]) {
                value[len][0] = i;
                value[len][1] = ch[i];
                len++;
            }
        }
        for (i = 0; i < len-1; i++) {
            for (j = 0; j < len-1; j++) {
                if ((value[j][1]>value[j+1][1]) || (value[j][1]==value[j+1][1])&&(value[j][0]<value[j+1][0])) {
                    tmp = value[j][0];
                    value[j][0] = value[j+1][0];
                    value[j+1][0] = tmp;
                    tmp = value[j][1];
                    value[j][1] = value[j+1][1];
                    value[j+1][1] = tmp;
                }
            }
        }

        if (first==1) {
            printf("\n");
        }
        else {
            first = 1;
        }
        for (i = 0; i < len; i++) {
            printf("%d %d\n", value[i][0], value[i][1]);
        }
    }
    return 0;
}
