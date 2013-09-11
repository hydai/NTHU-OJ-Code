#include <stdio.h>
#include <string.h>

#define LINE 15
#define LEN 210

char Article[LINE][LEN];
char Search[LEN];
int main(int argc, char *argv[])
{
    int N, M, i, len, j, len2, count, k;
    while (~scanf("%d%d", &N, &M)) {
        getchar();
        for (i = 0; i < N; i++) {
            gets(Article[i]);
            j = 0;
            while (Article[i][j]) {
                if (Article[i][j] >= 'A' && Article[i][j] <= 'Z') {
                    Article[i][j] += 32;
                }
                j++;
            }
        }
        for (i = 0; i < M; i++) {
            gets(Search);
            printf("%s:", Search);
            j = 0;
            while (Search[j]) {
                if (Search[j] >= 'A' && Search[j] <= 'Z') {
                    Search[j] += 32;
                }
                j++;
            }
            len = strlen(Search);
            count = 0;
            for (k = 0; k < N; k++) {
                len2 = strlen(Article[k]);
                for (j = 0; j + len <= len2; j++) {
                    if (strncmp(Article[k]+j, Search, len) == 0) {
                        count++;
                    }
                }
            }
            printf("%d\n", count);
        }
        putchar('\n');
    }
    return 0;
}
