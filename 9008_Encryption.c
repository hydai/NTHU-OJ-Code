#include <stdio.h>
#include <string.h>
#include <math.h>

#define LEN 33
#define MAX 1005
#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3
int Way[4][2] = {
    {0, -1},
    {0, 1},
    {1, 0},
    {-1, 0}
};
int Arr[LEN][LEN];
int limit, count;
void Find(int x, int y, int dir) {
    if (x < 1 || x > limit || y < 1 || y > limit)
        return ;

    while ((x >= 1 && x <= limit) || (y >= 1 && y <= limit)) {
        Arr[x][y] = count++;
        x += Way[dir][0];
        y += Way[dir][1];
    }
    x -= Way[dir][0];
    y -= Way[dir][1];

    if (dir == UP || dir == DOWN) {
        if (Arr[x+1][y] == -1) {
            Find(x+1, y, RIGHT);
        }
        else if (Arr[x-1][y] == -1) {
            Find(x-1, y, LEFT);
        }
    }
    else {
        if (Arr[x][y-1] == -1) {
            Find(x, y-1, UP);
        }
        else if (Arr[x][y+1] == -1) {
            Find(x, y+1, DOWN);
        }
    }
}

int main(int argc, char *argv[])
{
    int i, j, len, index;
    char str[MAX];
    double dsp;

    while (~scanf("%s", str)) {
        memset(Arr, -1, sizeof(Arr));
        len = strlen(str);
        limit = dsp = sqrt(len);
        limit = ((dsp-limit>0)?limit+1:limit);
        
        for (i = 0; i <= limit+1; i++) {
            Arr[0][i] = -2;
            Arr[i][0] = -2;
            Arr[limit+1][i] = -2;
            Arr[i][limit+1] = -2;
        }

        count = 0;
        Arr[1][1] = count++;
        Find(1, 1+1, DOWN);
        
        for (i = 1; i <= limit; i++) {
            for (j = 1; j <= limit; j++) {
                if (Arr[i][j] < len) {
                    putchar(str[Arr[i][j]]);
                }
            }
        }
        putchar(10);
    }
    return 0;
}

