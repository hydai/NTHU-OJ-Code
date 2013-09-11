#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 1000
#define NS 1001

int List[NS][LEN];

int main(int argc, char *argv[])
{
    int i, j, N;
    memset(List, 0, sizeof(List));
    List[1][0] = 1;
    List[2][0] = 1;

    for(i = 3; i < NS; i++) {
        for (j = 0; j < LEN-1; j++) {
            List[i][j] += List[i-1][j]+List[i-2][j];
            List[i][j+1] += List[i][j]/10;
            List[i][j] %= 10;
        }
    }

    while (~scanf("%d", &N)) {
        int ZERO = 0;
        for (i = LEN-1; i >= 0; i--) {
            if (!ZERO && List[N][i] == 0) {
                continue;
            }
            else {
                ZERO = 1;
            }
            putchar('0'+List[N][i]);
        }
        putchar(10);
    }
    return 0;
}
