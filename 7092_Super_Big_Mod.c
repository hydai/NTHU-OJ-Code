#include <stdio.h>
#include <math.h>

#define MAX 2

int main(int argc, char *argv[])
{
    int n, m, i, mode, ans;
    int arr[MAX][MAX], tmp[MAX][MAX], f0 = 0, f1 = 1;


    while (~scanf("%d%d", &n, &m)) {
        
        arr[0][0] = 1, arr[0][1] = 1, arr[1][0] = 1, arr[1][1] = 0;
        memcpy(tmp, arr, sizeof(tmp));
        ans = 1;

        mode = (int)pow(2, (double)m);
        
        for (i = 2; i <= n; i++) {
            
        }

        if (n==0) {
            ans = 0;
        }
        else if (n==1) {
            ans = 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
