#include <cstdio>
#include <cstring>
#include <sstream>
using namespace std;
int N;
int ans;
bool mapping[100+10][100+10];
bool isVisited[100+10];


int DFS(int st) {
    int edgeCt = 1;
    if (isVisited[st]) {
        return 0;
    }
    isVisited[st] = true;
    for (int i = 1; i <= N; i++) {
        if (!isVisited[i] && mapping[st][i]) {
            edgeCt += DFS(i);
        }
    }
    return edgeCt;
}

int main(int argc, char *argv[])
{
    int from, to;
    while (~scanf("%d", &N) && N) {
        memset(mapping, 0, sizeof(mapping));
        char tmpIn[50000];
        getchar();
        while(true) {
            gets(tmpIn);
            stringstream ss;
            ss << tmpIn;
            ss >> from;
            if (from == 0) {
                break;
            }
            while(ss >> to) {
                mapping[from][to] = true;
                mapping[to][from] = true;
            }
        }
        ans = 0;
        // test every node
        for (int i = 1; i <= N; i++) {
            int edgeCt = 0;
            memset(isVisited, 0, sizeof(isVisited));
            isVisited[i] = true;
            for (int i = 1; i <= N; i++) {
                if (!isVisited[i]) {
                    edgeCt = DFS(i);
                    break;
                }
            }
            ans += (edgeCt != (N-1))?(1):(0);
        }
        printf("%d\n", ans);
    }
    return 0;
}
