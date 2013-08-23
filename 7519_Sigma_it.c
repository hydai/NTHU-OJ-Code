#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10000

int main(int argc, char *argv[])
{
    int first, in[MAX_LEN], ans[MAX_LEN], tmp_int[MAX_LEN], length, i, j;
    char tmp_in[MAX_LEN], tmp_ch;

    while (~scanf("%s", tmp_in)) {
        memset(in, 0, sizeof(in)), memset(ans, 0, sizeof(ans));
        length = strlen(tmp_in);
        first = 1;
        for (i = 0; i < length; i++) {
            in[i] = tmp_in[length - i - 1]-'0';
        }
        memcpy(tmp_int, in, sizeof(tmp_int));
        tmp_int[0]++;
        for (i = 0; i < MAX_LEN; i++) {
            for (j = 0; j < length; j++) {
                ans[i+j]+=tmp_int[j]*in[i];
            }
        }
        for (i = 0; i < MAX_LEN; i++) {
            ans[i+1]+=ans[i]/10;
            ans[i]%=10;
        }

        for (i = MAX_LEN-1; i >= 0; i--) {
            if (first&&ans[i]==0) {
                continue;
            }
            else {
                first = 0;
            }
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
