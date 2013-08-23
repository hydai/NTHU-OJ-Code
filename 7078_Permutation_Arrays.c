#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char value[100000][500];
int main(int argc, char *argv[])
{
    int len, times, index, pos[100000]={0}, count, i;

    short flag = 0;
    scanf("%d", &times);

    while (times>0) {
        count = 0;
        if (flag) {
            printf("\n");
        }
        else {
            flag = 1;
        }
        while (1) {
            scanf("%d", &index);
            pos[index-1] = count;
            count++;
            if ('\n'==getchar()) {
                break;
            }
        }

        i = 0;
        while (i < count) {
            scanf("%s", value[i]);
            i++;
        }

        for (i = 0; i < count; i++) {
            printf("%s\n", value[pos[i]]);
        }
        times--;
    }
    
    return 0;
}
