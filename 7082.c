#include <stdio.h>

int main(int argc, char *argv[])
{
    int N, M, i, j;
    double ans;

    while (~scanf("%d%d", &N, &M)) {
        if (N==M && M==0) {
            break;
        }

        /*倒置*/
        if (M > N/2) {
            M = N-M;
        }
        
        ans = 1.0;
        for (i = 1; i <= M; ans*=(N-i+1), ans/=i, i++){}

        printf("%.0lf\n", ans);
    }
    return 0;
}
