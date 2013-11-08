#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>

using namespace std;
#define Size 100+10
#define INF 2147483647
int line[Size][Size];
int dis[Size][Size];
bool inQ[Size];
int main(int argc, char *argv[])
{
    int n, m, st, ed, u, v, tmpA, tmpB, tmpT;
    
    while (~scanf("%d%d", &n, &m)) {
        vector<pair<int, int> >Vec;
        memset(line, 0, sizeof(line));
        memset(dis, -1, sizeof(dis));
        memset(inQ, 0, sizeof(inQ));
        
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &u, &v);
            Vec.push_back(pair<int, int>(u, v));
            dis[u][v] = dis[v][u] = 1;
            line[u][v]++; line[v][u]++;
        }
        for (int i = 1; i <= n; i++) {
            
        }
        
        queue<int> Queue;
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
