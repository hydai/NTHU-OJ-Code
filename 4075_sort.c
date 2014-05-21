#include <stdio.h>
#include <stdlib.h>
int m;

int cmp(const void* s1, const void* s2) {
    int a = *(int *)s1;
    int b = *(int *)s2;
    if (a % 2 == 1 && b % 2 == 1) {
        /* code */
    }
}

int main(int argc, char *argv[])
{
    int n;
    int arr[100000];
    while (~scanf("%d%d", &n, &m) && (n!=0 && m!=0)) {
        int i;
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        qsort(arr, n, sizeof(arr[0]), cmp);
    }
    return 0;
}
