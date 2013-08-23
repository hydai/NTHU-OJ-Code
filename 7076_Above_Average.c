#include <stdio.h>
#include <stdlib.h>

int C, N, P[1001], up;
double sum;
int main(int argc, char *argv[])
{
    int i, j;
    scanf("%d", &C);
    for (i = 0; i < C; i++) {
        scanf("%d", &N);
        sum = 0.0;
        up = 0;
        for (j = 0; j < N; j++) {
            scanf("%d", &P[j]);
            sum += P[j];
        }
        sum /= N;
        for (j = 0; j < N; j++) {
            if (P[j] > sum) {
                up++;
            }
        }
        printf("%.3lf%%\n", (double)up*100/N);
    }
    return 0;
}
