#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000+30

int compare(const int s1[], const int s2[])
{
    int a[2];
    int b[2];

    a[0] = s1[0];
    a[1] = s1[1];
    b[0] = s2[0];
    b[1] = s2[1];

    if (s1[1]<s2[1]) {
        return -1;
    }

}

int main(int argc, char *argv[])
{
    char string[MAX_LEN];
    int ch[140] = {0};
    int value[140][2], len, i, j;

    while (NULL!=gets(string)) {
        memset(ch, 0, sizeof(ch));
        memset(value, 0, sizeof(value));

        len = strlen(string)-1;
        while (len--) {
            ch[i]++;
        }
        
        j = 0;
        for (i = 0; i < 140; i++) {
            if (ch[i]) {
                value[j][0] = i;
                value[j][1] = ch[i];
                j++;
            }
        }

        qsort(value[][2], j, 2*sizeof(int), compare);


    }
    return 0;
}
