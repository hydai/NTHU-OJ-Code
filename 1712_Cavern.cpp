#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;
#define Size 100000+10
#define INF 2147483647
int dis[Size];
bool inQ[Size];
int parent[Size];
int main(int argc, char *argv[])
{
    int t, n, m, st, ed, tmpA, tmpB, tmpT;
    scanf("%d", &t);
    while (t--) {
        queue<int> Queue;
        vector<pair<int, int> >Vec[Size];
        memset(inQ, false, sizeof(inQ));
        memset(parent, -1, sizeof(parent));
        scanf("%d%d%d%d", &n, &m, &st, &ed);
        for (int i = 0; i <= n; i++) {
            dis[i] = INF;
        }
        
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &tmpA, &tmpB, &tmpT);
            Vec[tmpA].push_back(pair<int, int>(tmpB, tmpT));
            Vec[tmpB].push_back(pair<int, int>(tmpA, tmpT));
        }
        dis[ed] = 0;
        Queue.push(ed);
        while (!Queue.empty()) {
            int from = Queue.front(); Queue.pop();
            inQ[from] = false;
            for (int i = 0; i < Vec[from].size(); i++) {
                int to = Vec[from][i].first, d = Vec[from][i].second;
                if (dis[from] + d < dis[to]) {
                    dis[to] = dis[from] + d;
                    parent[to] = from;
                    if (inQ[to] == false) {
                        inQ[to] = true;
                        Queue.push(to);
                    }
                }
                else if (dis[from] + d == dis[to] && from < parent[to]) {
                    parent[to] = from;
                }
            }
        }
        // trace path
        int x = st;
        printf("%d", x);
        while (parent[x] != -1) {
            printf("->%d", parent[x]);
            x = parent[x];
        }
        putchar(10);
    }
    return 0;
}
