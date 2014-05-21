#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define PII pair<int,int>
vector< PII > V[45];
vector< int > Path;
bool edgeUsed[2000];
int st, space, EDGE;
int degree[45];
void init();
void addEdge(int, int, int);
void vsort();
bool cmp(PII, PII);
bool checkPT();
void find_circuit(int);
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
            vsort();
            solve();
        }
        putchar(10);
    }
    return 0;
}
void init() {
    memset(degree, 0, sizeof(degree));
    memset(edgeUsed, 0, sizeof(edgeUsed));
    Path.clear();
    for (int i = 0; i < 45; i++) {
        V[i].clear();
    }
    st = -1;
    EDGE = 0;
}
void addEdge(int x, int y, int z) {
    PII tmp =  PII (y,z);
    V[x].push_back(tmp);
    tmp.first = x;
    V[y].push_back(tmp);
    degree[x]++;
    degree[y]++;
    EDGE++;
}
void vsort() {
    for (int i = 0; i < 45; i++) {
        sort(V[i].begin(), V[i].end(), cmp);
    }
}
bool cmp(PII A, PII B) {
    if (A.second != B.second) {
        if (A.second > B.second) {
            return false;
        } else {
            return true;
        }
    }
    return false;
}
void solve() {
    space = 0;
    find_circuit(st);
    int used[2000] = {0};
    vector <int> VV;
    for (int i = 0; i < Path.size(); i++) {
        if (used[Path[i]] == 0) {
            VV.push_back(Path[i]);
            used[Path[i]] = 1;
        }
    }
    for (int i = VV.size()-1; i >= 0; i--) {    
        if (space++) {
            putchar(32);
        }
        printf("%d", VV[i]);
    }
    putchar(10);
}
void find_circuit(int i) {
    vector< PII >::iterator iter = V[i].begin();
    vector< PII >::iterator removeIT;
    for (; iter != V[i].end(); iter++) {
        if (iter->second == -1)
            continue;
        int tmp = iter->first;
        int tmp2 = iter->second;
        if (degree[i] != 0) {
            degree[i]--;
            for (removeIT = V[tmp].begin(); removeIT != V[tmp].end(); removeIT++) {
                if (removeIT->first == i && removeIT->second == iter->second) {
                    removeIT->second = -1;
                    break;
                }
            }
            iter->second = -1;
            find_circuit(tmp);
        }
        Path.push_back(tmp2);
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
