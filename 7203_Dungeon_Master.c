#include <stdio.h>
#include <string.h>

int move[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
int map[32][32][32], isused[32][32][32];
int Q[50000][3];

int main(int argc, char *argv[])
{
    int L, R, C, i, j, k, map[32][32][32];
    while (scanf("%d%d%d", &L, &R, &C)) {
        if (!(L+R+C)) { break; }
        memset(map, 0, sizeof(map));


    }
    return 0;
}
