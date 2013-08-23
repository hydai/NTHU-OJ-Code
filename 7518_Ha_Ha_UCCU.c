#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100000+100

char unit_in[300], total_in[MAX_LEN][30];

int main(int argc, char *argv[])
{
    int length, i, half, bool, n;
    
    while (~scanf("%s", unit_in)) {
        n = 0;
        memset(total_in, 0, sizeof(total_in));
        strcat(total_in[n++], unit_in);
        while (getchar()!='\n') {
            scanf("%s", unit_in);
            strcat(total_in[n++], unit_in);
        }
        length = n;
        half = length/2;
        bool = 1;
        for (i = 0; i < half; i++) {
            if (strcmp(total_in[i], total_in[length-i-1])!=0) {
                bool = 0;
            }
        }
        printf("%s\n", (bool)?"YES":"NO");
    }
    return 0;
}
