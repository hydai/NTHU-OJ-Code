#include <stdio.h>
int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char mv[4] = {'D', 'U', 'R', 'L'};
int main(int argc, char *argv[])
{
    int map[5][5] = {0};
    int i, j, st_x, st_y, tmp_x, tmp_y;
    for (i = 1; i <= 3; i++)
        for (j = 1; j <= 3; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1) st_x = i, st_y = j;
        }
    putchar('*');
    j = 1;
    while (map[st_x][st_y] != 9 && j) {
        j = 0;
        for (i = 0; i < 4; i++) {
            tmp_x = st_x + move[i][0], tmp_y = st_y + move[i][1];
            if (map[tmp_x][tmp_y] == map[st_x][st_y]+1) {
                putchar(mv[i]); j++; st_x = tmp_x; st_y = tmp_y; break;
            }
        }
    }
    putchar('\n');
    return 0;
}
