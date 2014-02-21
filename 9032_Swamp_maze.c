#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int SIZE = 105;
const int MAX = 1e9;

typedef struct {
    int x, y;
} pair;

int mv[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main(int argc, char *argv[])
{
int i, j, k;
int T; 
int H, W;
int q_head, q_tail;
int dis[SIZE][SIZE];
int in[SIZE][SIZE];
char map[SIZE][SIZE];
char buffer[SIZE];
pair st, ed;
pair q[100000];
scanf("%d", &T);
while (T--) {
    scanf("%d%d", &H, &W);
    memset(map, -1, sizeof(map));
    memset(in, 0, sizeof(in));
    for (i = 0; i <= H; i++) for (j = 0; j <= W; j++) dis[i][j] = MAX;
    for (i = 1; i <= H; i++) {
        scanf("%s", buffer);
        for (j = 1; j <= W; j++) {
            if (buffer[j-1] == 'S') {
                st.x = i; st.y = j;
                map[i][j] = -1;
            }
            else if (buffer[j-1] == '#') {
                map[i][j] = -1;
            }
            else if (buffer[j-1] == '@') {
                map[i][j] = 2;
            }
            else if (buffer[j-1] == '.') {
                map[i][j] = 1;
            }
            else if (buffer[j-1] == 'G') {
                map[i][j] = 1;
                ed.x = i; ed.y = j;
            }
        }
    }
    dis[st.x][st.y] = 0;
    q_head = q_tail = 0;
    q[q_tail++] = st;
    while (q_head != q_tail) {
        pair cur = q[q_head++];
        in[cur.x][cur.y] = 0;
        for (i = 0; i < 4; i++) {
            pair tmp; tmp.x = cur.x+mv[i][0]; tmp.y = cur.y+mv[i][1];
            if (map[tmp.x][tmp.y] == -1) continue;
            if (dis[cur.x][cur.y] + map[tmp.x][tmp.y] < dis[tmp.x][tmp.y]){ 
                dis[tmp.x][tmp.y] = dis[cur.x][cur.y] + map[tmp.x][tmp.y];
                if (in[tmp.x][tmp.y] == 0){ 
                    in[tmp.x][tmp.y] = 1;
                    q[q_tail++] = tmp;
                }
            }
        }
    }
    if (dis[ed.x][ed.y] == MAX) {
        printf("-1\n");
    }
    else {
        printf("%d\n", dis[ed.x][ed.y]);
    }
}
return 0;
}
