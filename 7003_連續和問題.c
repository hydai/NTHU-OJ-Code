#include <stdio.h>

int test(int *arr, int n, int x);

int main(int argc, char *argv[])
{
    int t, n, x, arr[500000], bool;
    int i;
    scanf("%d", &t);
    while (t > 0) {
        scanf("%d%d", &n, &x);
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        bool = test(arr, n, x);
        
        if (bool) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }

        t--;
    }
    return 0;
}

int test(int *arr, int n, int x)
{
    int i, j, sum;
    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = i; j < n; j++) {
            sum += arr[j];
            if (sum == x) {
                return 1;
            }
            else if (sum > x) {
                break;
            }
        }
    }
    return 0;
}
