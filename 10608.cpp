#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;
#define SIZE 30000+100
int n, m, MAX;
vector<int> Link[SIZE];
int used[SIZE];
int max_(int a, int b) {
    return (a > b)?a:b;
}
int dfs(int pt, int dep) {
    int tmp = 0;
    for (int i = 0; i < Link[pt].size(); i++) {
        if (used[Link[pt][i]] == 0) {
            used[Link[pt][i]] = 1;
            tmp = dfs(Link[pt][i], dep+1);
            dep = max_(dep, tmp);
        }
    }
    return dep;
}
void init(int n) {
    for (int i = 0; i <= n; i++) {
        Link[i].clear();
        used[i] = 0;
    }
}
int main(int argc, char *argv[])
{
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        init(n);
        while (m--) {
            int a, b;
            scanf("%d%d", &a, &b);
            Link[a].push_back(b);
            Link[b].push_back(a);
        }
        MAX = 0;
        for (int i = 1; i <= n; i++) {
            if (used[i] == 0) {
                used[i] = 1;
                MAX = max_(MAX, dfs(i, 1));
            }
        }
        printf("%d\n", MAX);
    }
    return 0;
}
