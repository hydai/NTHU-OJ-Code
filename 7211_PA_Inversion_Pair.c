#include <stdio.h>
#include <string.h>

#define MAX_LEN 1050

int main(int argc, char *argv[])
{
    int pair, tmp_in[MAX_LEN], i, j;
    
    while (~scanf("%d", &tmp_in[0])) {
        pair = 0;i = 1;
        while (1) {
            if (getchar()=='\n') {break;}
            scanf("%d", &tmp_in[i++]);
            for (j = i-2; j >= 0; j--) {
                if (tmp_in[i-1]<tmp_in[j]) {
                    pair++;
                }
            }
        }
        printf("%d\n", pair);
    }
    return 0;
}
