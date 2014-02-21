#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
int diff, n, G1, G2;
vector<int> V;
int ABS(int a, int b) {
    if (a>b)
        return a-b;
    return b-a;
}

void dfs(int aa) {
    if (aa == n) {
        if (diff > ABS(G1, G2))
            diff = ABS(G1, G2);
        return;
    }
    G1+=V[aa];
    dfs(aa+1);
    G1-=V[aa];
    G2+=V[aa];
    dfs(aa+1);
    G2-=V[aa];
}

int main(int argc, char *argv[])
{
    int tmp;
    while (~scanf("%d", &n) && n!=0) {
        V.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            V.push_back(tmp);
        }
        sort(V.begin(), V.end());
        diff = 1e9;
        G1 = G2 = 0;
        dfs(0);
        printf("%d\n", diff);
    }
    return 0;
}
