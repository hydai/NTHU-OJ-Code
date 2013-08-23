#include <stdio.h>
#include <stdlib.h>

#define MAX 2147483648

int arr[MAX][MAX];

int main(int argc, char *argv[])
{
    int N, M, i, j;
    memset(arr, 0, sizeof(arr));
    
    for (i = 0; i < MAX; i++) {
        arr[i][0] = 1;
    }
    for (i = 1; i < MAX; i++) {
        for (j = 1; j < MAX; j++) {
            arr[i][j] = arr[i-1][j]+arr[i-1][j-1];
        }
    }

    while (~scanf("%d%d", &N, &M)) {
        if (N==M && M==0) {
            break;
        }
        if (M > N/2) {
            M = N-M;
        }

        printf("%d\n", arr[N][M]);
    }
    return 0;
}
