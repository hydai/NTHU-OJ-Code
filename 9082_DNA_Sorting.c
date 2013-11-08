#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000+10
#define LEN 15

int L;
char List[MAX][LEN];
int getValue(char *input) {
    int i, ans = 0, V[4] = {0};
    for (i = 0; i < L; i++) {
        if (input[i] == 'A') {
            ans += (V[1]+V[2]+V[3]);
            V[0]++;
        }
        else if (input[i] == 'C') {
            ans += (V[2]+V[3]);
            V[1]++;
        }
        else if (input[i] == 'G') {
            ans += V[3];
            V[2]++;
        }
        else {
            V[3]++;
        }
    }
    return ans;
}

int cmp(const void *s1, const void *s2) {
    char *a = (char*)s1;
    char *b = (char*)s2;
    int ansA, ansB;
    ansA = getValue(a);
    ansB = getValue(b);
    if (ansA < ansB) {
        return -1;
    }
    else if (ansA == ansB && strcmp(a, b)<0) {
        return -1;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    int N, i;
    while (~scanf("%d%d", &N, &L)) {
        for (i = 0; i < N; i++) {
            scanf("%s", List[i]);
        }
        qsort(List, N, sizeof(List[0]), cmp);
        for (i = 0; i < N; i++) {
            printf("%s\n", List[i]);
        }
    }
    return 0;
}
