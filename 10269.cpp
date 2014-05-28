#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
int min_(int a, int b) {
    return (a>b)?b:a;
}
struct AA {
    int id, sh;
    AA (int _id, int _sh) {
        id = _id;
        sh = _sh;
    }
};
using namespace std;
int main(int argc, char *argv[])
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int A, B, M, L, K;
        int road[110][110];
        for (int i = 0; i < 110; i++) {
            for (int j = 0; j < 110; j++) {
                if (i == j)
                    road[i][j] = 0;
                else
                    road[i][j] = 1100000000;
            }
        }
        scanf("%d%d%d%d%d", &A, &B, &M, &L, &K);
        for (int i = 0; i < M; i++) {
            int x, y, l;
            scanf("%d%d%d", &x, &y, &l);
            road[x][y] = l;
            road[y][x] = l;
        }
        // for-for-for
        for (int k = 1; k <= A; k++) {
            for (int i = 1; i <= A+B; i++) {
                for (int j = 1; j <= A+B; j++) {
                    if (i == j || road[i][k] == 1100000000 || road[k][j] == 1100000000)
                        continue;
                    road[i][j] = min_(road[i][j], road[i][k]+road[k][j]);
                }
            }
        }
        // spfa
        int dis[110][110];
        for (int i = 0; i < 110; i++) {
            for (int j = 0; j < 110; j++) {
                dis[i][j] = 1100000000;
            }
        }
        int inq[110][110] = {0};
        queue<AA> Q;
        dis[A+B][0] = 0;
        Q.push(AA(A+B, 0));
        inq[A+B][0] = 1;
        while (!Q.empty()) {
            AA tmp = Q.front(); Q.pop();
            inq[tmp.id][tmp.sh] = 0;
            for (int i = 1; i <= A+B; i++) {
                if (tmp.id != i) {
                    if (tmp.sh < K && road[tmp.id][i] <= L) {
                        // can run
                        if (dis[i][tmp.sh+1] > dis[tmp.id][tmp.sh]) {
                            // cost 1 of K
                            dis[i][tmp.sh+1] = dis[tmp.id][tmp.sh];
                            if (inq[i][tmp.sh+1] == 0) {
                                inq[i][tmp.sh+1] = 1;
                                Q.push(AA(i, tmp.sh+1));
                            }
                        }
                    }
                    if (dis[i][tmp.sh] > dis[tmp.id][tmp.sh] + road[tmp.id][i]) {
                        // normal spfa
                        dis[i][tmp.sh] = dis[tmp.id][tmp.sh] + road[tmp.id][i];
                        if (inq[i][tmp.sh] == 0) {
                            inq[i][tmp.sh] = 1;
                            Q.push(AA(i, tmp.sh));
                        }
                    }
                }
            }
        }
        int ans = 1100000000;
        for (int i = 0; i <= K; i++) {
            ans = min_(ans, dis[1][i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
