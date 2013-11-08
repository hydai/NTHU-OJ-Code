#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int List[1000000+100];

int cmp(const void *s1, const void *s2) {
    int a = *(int *)s1, b = *(int *)s2;
    if (a > b) {
        return -1;
    }
    else if (a < b) {
        return 1;
    }
    else {
        return 0;
    }
}

int main(int argc, char *argv[])
{
    int N, Q, i, X, space = 0;
    int *ptr;
    while (~scanf("%d", &N) && N) {
        if (space++) {
            putchar(10);
        }
        for (i = 0; i < N; i++) {
            scanf("%d", &X);
            List[i] = X;
        }
        qsort(List, N, sizeof(List[0]), cmp);
        scanf("%d", &Q);
        for (i = 0; i < Q; i++) {
            scanf("%d", &X);
            ptr = (int *) bsearch(&X, List, N, sizeof(X), cmp);
            if (ptr) {
                printf("Yes\n");
            }
            else {
                printf("No\n");
            }
        }
    }
    return 0;
}
