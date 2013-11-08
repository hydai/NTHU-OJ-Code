#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10000+100
#define LEN 20
char List[MAX][LEN];

int cmp (const void *s1, const void *s2) {
    return strcmp((char *)s1, (char *)s2);
}

int main(int argc, char *argv[])
{
    int N, M, K, count;
    int i;
    char tmp[LEN], *ptr;
    while (~scanf("%d%d", &N, &M)) {
        for (i = 0; i < N; i++) {
            scanf("%s", List[i]);
        }
        qsort(List, N, sizeof(List[0]), cmp);

        while (M--) {
            scanf("%d", &K);
            count = 0;
            for (i = 0; i < K; i++) {
                scanf("%s", tmp);
                ptr = bsearch(tmp, List, N, sizeof(List[0]), cmp);
                if (ptr) {
                    count++;
                }
            }
            if (count > K/2) {
                putchar('Y');
            }
            else {
                putchar('N');
            }
            putchar(10);
        }
    }
    return 0;
}
