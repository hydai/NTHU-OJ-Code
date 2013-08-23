#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000+100

int main(int argc, char *argv[])
{
    int T, n, in[MAX], nn, i, j, tmp;
    memset(in, 0, sizeof(in));

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", &in[i]);
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n-1; j++) {
                if (in[j]>in[j+1]) {
                    tmp = in[j];
                    in[j] = in[j+1];
                    in[j+1] = tmp;
                }
            }
        }
        for (i = 0; i < n-1; i++) {
            printf("%d ", in[i]);
        }
        printf("%d\n", in[i]);
    }

    return 0;
}
