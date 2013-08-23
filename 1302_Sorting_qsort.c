#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000+100

int compare(const void* source1, const void* source2)
{
    return *(int *)source1-*(int *)source2;
}

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

        qsort(in, n, sizeof(int), compare);
        for (i = 0; i < n-1; i++) {
            printf("%d ", in[i]);
        }
        printf("%d\n", in[i]);
    }

    return 0;
}
