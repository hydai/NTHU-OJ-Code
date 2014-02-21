#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int main(int argc, char *argv[])
{
    int t, r, x, i;
    int arr[510];
    scanf("%d", &t);
    while (t--) {
        int ans = 0;
        scanf("%d", &r);
        for (x = 0; x < r; x++) {
            scanf("%d", &arr[x]);
        }
        sort(arr, arr+r);
        if (r % 2 == 1) {
            x = arr[(r+1)/2-1];
        }
        else {
            x = (arr[r/2-1] + arr[r/2])/2;
        }
        for (i = 0; i < r; i++) {
            ans += abs(arr[i] - x);
        }
        printf("%d\n", ans);
    }
    return 0;
}
