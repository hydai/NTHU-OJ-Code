#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;
struct AA {
    int table[9][9], size, ct, res;
    AA rotate() {
        AA tmp;
        tmp.init(size, res);
        for (int i = 0; i < 2*size+1; i++) {
            for (int j = 0; j < 2*size+1; j++) {
                tmp.table[i][j] = table[j][2*size-i];
            }
        }
        return tmp;
    }
    int down() {
        int status = 2;
        for (int j = 1; j < 2*size+1; j+=2) {
            for (int i = 2*size-3; i > 0; i-=2) {
                if (table[i][j] >= 1) {
                    for (int k = i+2; k < 2*size+1; k+=2) {
                        if (table[k-1][j] == -100 || table[k][j] >= 1) {
                            if (i != k-2) {
                                int tmp = table[k-2][j]; table[k-2][j] = table[i][j]; table[i][j] = tmp;
                            }
                            break;
                        } else if (table[k][j] < 0) {
                            if (table[k][j] != (table[i][j]*(-1))) {
                                status = 0;
                                return status;
                            } else {
                                table[i][j] = 0;
                                table[k][j] = 0;
                                res--;
                                if (res == 0) {
                                    status = 1;
                                    return status;
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
        return status;
    }
    void addct() {
        ct+=1;
    }
    void init(int nn, int mm) {
        ct = 0;
        size = nn;
        res = mm;
        memset(table, 0, sizeof(table));
        for (int i = 0; i < 2*size+1; i++) {
            table[0][i] = -100;
            table[2*size][i] = -100;
            table[i][0] = -100;
            table[i][2*size] = -100;
        }
    }
};
int main(int argc, char *argv[])
{
    int N, M, W, ct = 0;
    while (~scanf("%d%d%d", &N, &M, &W)) {
        if (N == 0 && M == 0 && W == 0) {
            break;
        }
        queue<AA> Q;
        AA initial;
        initial.init(N, M);
        printf("Case %d: ", ++ct);
        for (int i = 0; i < M; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            initial.table[2*x+1][2*y+1] = i+1;
        }
        for (int i = 0; i < M; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            initial.table[2*x+1][2*y+1] = -(i+1);
        }
        for (int i = 0; i < W; i++) {
            int x, y, xx, yy;
            scanf("%d%d%d%d", &x, &y, &xx, &yy);
            x = ((2*xx+1) + (2*x+1))/2;
            y = ((2*yy+1) + (2*y+1))/2;
            initial.table[x][y] = -100;
        }
        Q.push(initial);
        int mans = 0;
        bool hasAns = false;
        while (!Q.empty()) {
            AA tmp = Q.front();
            tmp.addct();
            // DOWN, RIGHT, UP, LEFT
            for (int i = 0; i < 4; i++) {
                AA tmp2 = tmp;
                tmp = tmp.rotate();
                int status = tmp2.down();
                if (status == 0) {              // Error occurs
                    continue;
                } else if (status == 1) {       // Finish
                    hasAns = true;
                    mans = tmp2.ct;
                    break;
                } else {                        // Other
                    Q.push(tmp2);
                }
            }
            if (hasAns) {
                break;
            }
            Q.pop();
        }
        if (hasAns) {
            printf("%d moves\n", mans);
        } else {
            printf("impossible\n");
        }
    }
    return 0;
}
