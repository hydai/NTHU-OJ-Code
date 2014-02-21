#include <stdio.h>
#include <string.h>
const int SIZE = 200000+512;

int disjointset[SIZE];
int countsort[SIZE];
int i, j, n, k;

void init() {
    for (i = 0; i < n; i++) {
        disjointset[i] = i;
        countsort[i] = 0;
    }
}

int find(int node) {
    return (disjointset[node] == node)?node:(disjointset[node] = find(disjointset[node]));
}

int count() {
    int ans = 0;
    for (i = 0; i < n; i++) {
        countsort[find(i)]++;
    }
    for (i = 0; i < n; i++) {
        if (countsort[i] > ans) ans = countsort[i];
    }
    return ans;
}

int main(int argc, char *argv[])
{
    while (~scanf("%d%d", &n, &k) && n != 0) {
        init();
        for (i = 1; i <= k; i++) {
            int a, b, fa, fb;
            scanf("%d%d", &a, &b);
            fa = find(a);
            fb = find(b);
            if (fa != fb) {
                disjointset[fa] = fb;
            }
        }

        printf("%d\n", count());
    }
    return 0;
}
