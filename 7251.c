#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int leader[30000+10];
int size[30000+10];
int max;
int getLeader(int x) {
    if (x != leader[x]) {
        leader[x] = getLeader(leader[x]);
    }
    return leader[x];
}
void link(int A, int B) {
    int x = getLeader(A), y = getLeader(B);
    leader[x] = y;
}
int main(int argc, char *argv[])
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, M, i;
        max = 0;
        scanf("%d%d", &N, &M);
        for (i = 1; i <= N; i++) {
            leader[i] = i;
            size[i] = 0;
        }
        for (i = 0; i < M; i++) {
            int A, B;
            scanf("%d%d", &A, &B);
            link(A, B);
        }
        for (i = 1; i <= N; i++) {
            size[getLeader(i)]++;
        }
        for (i = 1; i <= N; i++) {
            if (max < size[i]) {
                max = size[i];
            }
        }
        printf("%d\n", max);
    }
    return 0;
}
