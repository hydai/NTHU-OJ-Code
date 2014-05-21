#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int V[45][45];
vector< int > Path;
int st, space, EDGE;
int degree[45];
void init();
void addEdge(int, int, int);
bool checkPT();
void find_circuit(int, int);
void solve();
int main(int argc, char *argv[])
{
    int x, y, z;
    while (~scanf("%d%d", &x, &y)) {
        init();
        if (x == 0 && y == 0) {
            break;
        }
        st = (x > y)?(y):(x);
        scanf("%d", &z);
        addEdge(x, y, z);
        while (~scanf("%d%d", &x, &y)) {
            if (x == 0 && y == 0) {
                break;
            }
            scanf("%d", &z);
            addEdge(x, y, z);
        }
        if (!checkPT()) {
            printf("Round trip does not exist.\n");
        } else {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    printf("%d ", V[i][j]);
                }
                putchar(10);
            }
            solve();
        }
        putchar(10);
    }
    return 0;
}
void init() {
    memset(degree, 0, sizeof(degree));
    Path.clear();
    memset(V, -1, sizeof(V));
    st = -1;
    EDGE = 0;
}
void addEdge(int x, int y, int z) {
    V[x][y] = z;
    V[y][x] = z;
    degree[x]++;
    degree[y]++;
    EDGE++;
}
void solve() {
    space = 0;
    find_circuit(st, 0);
    for (int i = 0; i < EDGE; i++) {    
        if (space++) {
            putchar(32);
        }
        printf("%d", Path[Path.size()-1-i]);
    }
    putchar(10);
}
void find_circuit(int i, int d) {
    for (int ii = 0; ii < 45; ii++) {
        if (V[i][ii] != -1) {
            int tmp = V[i][ii];
            if (degree[i] != 0) {
                degree[i]--;
                V[i][ii] = -2;
                V[ii][i] = -2;
                find_circuit(ii, d+1);
            } else {
                Path.push_back(tmp);
            }
        }
    }
}
bool checkPT() {
    int oddPT = 0;
    for (int i = 0; i < 45; i++) {
        if (degree[i] % 2) {
            oddPT++;
        }
    }
    return (oddPT != 0)?(false):(true);
}
