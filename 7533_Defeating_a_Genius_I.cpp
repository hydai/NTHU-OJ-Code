#include <cstdio>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
    int arr[12], n, k, len, first;
    while (~scanf("%d%d", &n, &k)) {
        first = 0; len = n;
        if (n==0&&k==0) {break;}
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        sort(arr, arr+len);
        
        for (int i = 0; i < k-1;i++)
        {
            next_permutation(arr, arr+len);
        }
        for (int i = 0; i < len; i++)
        {
            if (first++) {
                putchar(32);
            }
            printf("%d", arr[i]);
        }
        putchar(10);
    }

    return 0;
}
