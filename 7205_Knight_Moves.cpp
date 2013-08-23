#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;

#define LEN 8
#define MAX 10000
struct pt{
    int x, y, dis;
};
queue <pt> m_queue;
int move[8][2] = {
    {2,1},
    {1,2},
    {-1,2},
    {-2,1},
    {-2,-1},
    {-1,-2},
    {1,-2},
    {2,-1}
};

int main(int argc, char *argv[])
{
    int start_x, start_y, final_x, final_y, tmp_x, tmp_y, count;
    int i, queue_ct;
    pt tmp_pt, tmp_in_pt;
    char in_tmp[20];
    int is_visit[LEN][LEN];

    while (gets(in_tmp)!=NULL) {
        memset(is_visit, 0, sizeof(is_visit));
        while (!m_queue.empty()) {
            m_queue.pop();
        }

        start_x = in_tmp[0] - 'a';
        start_y = in_tmp[1] - '1';
        final_x = in_tmp[3] - 'a';
        final_y = in_tmp[4] - '1';

        tmp_pt.x = start_x; tmp_pt.y = start_y; tmp_pt.dis = 0;
        m_queue.push(tmp_pt);
        is_visit[start_x][start_y] = 1;
        while (!m_queue.empty()) {
            tmp_pt = m_queue.front(); 
            m_queue.pop();
            if (tmp_pt.x==final_x && tmp_pt.y==final_y) {
                printf("To get from %c%c to %c%c takes %d knight moves.\n", start_x+'a', start_y+'1', final_x+'a', final_y+'1', tmp_pt.dis); 
                break;
            }
            for (i = 0; i < 8; i++) {
                tmp_in_pt.x = tmp_pt.x+move[i][0];
                tmp_in_pt.y = tmp_pt.y+move[i][1];
                tmp_in_pt.dis = tmp_pt.dis;
                if (tmp_in_pt.x>=0&&tmp_in_pt.x<8 && tmp_in_pt.y>=0&&tmp_in_pt.y<8 && is_visit[tmp_in_pt.x][tmp_in_pt.y]==0) {
                    is_visit[tmp_in_pt.x][tmp_in_pt.y] = 1;
                    tmp_in_pt.dis++;
                    m_queue.push(tmp_in_pt);
                }
            }
        }
    }
    return 0;
}
