#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

int compare(const void *a, const void *b)
{
    return *(int*)a-*(int*)b;
}

int main(int argc, char *argv[])
{
    int n, q, arr[MAX], length, want;
    while (~scanf("%d%d", &n, &q)) {
        length = n;
        while (n>0) {
            scanf("%d", &arr[length-n]);
            n--;
        }
        qsort(arr, length, sizeof(int), compare);
        while (q>0) {
            scanf("%d", &want);
            printf("%d\n", arr[want-1]);
            q--;
        }
    }
    return 0;
}
