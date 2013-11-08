#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1001
#define LEN 55

int cmp(const void *s1, const void *s2) {
    return strcmp((char *)s1, (char *)s2);

}

int main(int argc, char *argv[])
{
    char name[MAX][LEN];
    int i, N;

    while (~scanf("%d", &N) && N) {
        for (i = 0; i < N; i++) {
            scanf("%s", name[i]);
        }
        qsort(name, N, LEN*sizeof(char), cmp);
        for (i = 0; i < N; i++) {
            printf("%s\n", name[i]);
        }
        putchar(10);
    }
    return 0;
}
