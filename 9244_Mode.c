#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000+10

int main(int argc, char *argv[])
{
    int mode[MAX_LEN]={0}, n, input, i, max_mode = 0, max_index = -1;
    while (~scanf("%d", &n)) {
        if (n==0) {
            break;
        }
        while (n--) {
            scanf("%d", &input);
            mode[input]++;
        }
        for (i = 999; i >= 0; i--) {
            if (mode[i]>max_mode) {
                max_mode = mode[i];
                max_index = i;
            }
            else if (mode[i]==max_mode) {
                if (i<max_index) {
                    max_index = i;
                }
            }
        }
        printf("%d\n", max_index);

        memset(mode, 0, sizeof(mode));
        max_mode = 0, max_index = -1;
    }

    return 0;
}
