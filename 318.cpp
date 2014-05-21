#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int n, m, ct = 1;
int from, to, v;
int inq[550], dis[550];
struct AA {
    int y, dis;
    AA(int _y, int _dis) {
        y = _y;
        dis = _dis;
    }
};
vector<AA> V[550];
void init() {
    for (int i = 0; i <= n; i++) {
        V[i].clear();
    }
    for (int i = 0; i < 550; i++) {
        dis[i] = 2147483647;
    }
    memset(inq, 0, sizeof(inq));
}
void spfa() {
    int st = 1;
    dis[st] = 0;
    queue<int> Q;
    Q.push(st);
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        inq[cur] = 0;
        for (int i = 0; i < V[cur].size(); i++) {
            AA tmp = V[cur][i];
            if (dis[cur] + tmp.dis < dis[tmp.y]) {
                dis[tmp.y] = dis[cur]+tmp.dis;
                if (!inq[tmp.y]) {
                    Q.push(tmp.y);
                }
            }
        }
    }
}
int main(int argc, char *argv[])
{
    while (~scanf("%d%d", &n, &m)) {
        if (n == 0 && m == 0) {
            break;
        }
        init();
        for (int i = 0; i < m; i++) {
            scanf("%d%d%d", &from, &to, &v);
            V[from].push_back(AA(to, v));
            V[to].push_back(AA(from, v));
        }
        spfa();
        double PMAX = 0, MMAX = 0;
        int Pindex = 1, Min1 = 1, Min2 = 1;
        for (int i = 0; i <= 500; i++) {
            if (dis[i] != 2147483647) {
                if (dis[i] > PMAX) {
                    PMAX = dis[i];
                    Pindex = i;
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < V[i].size(); j++) {
                int mmax = (dis[i] > dis[V[i][j].y])?dis[i]:dis[V[i][j].y];
                int mmin = (dis[i] > dis[V[i][j].y])?dis[V[i][j].y]:dis[i];
                double tmp = (mmin + V[i][j].dis - mmax)/2.0 + mmax;
                if (tmp > MMAX) {
                    MMAX = tmp;
                    Min1 = i;
                    Min2 = V[i][j].y;
                }
            }
        }
        printf("System #%d\n", ct++);
        if (PMAX >= MMAX) {
            printf("The last domino falls after %.1lf seconds, at key domino %d.\n\n", PMAX, Pindex);
        } else {
            if (Min1 > Min2) {
                int t = Min1; Min1 = Min2; Min2 = t;
            }
            printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n\n", MMAX, Min1, Min2);
        }
    }
    return 0;
}
