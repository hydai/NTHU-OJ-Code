#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 8
#define MAX 100000
#define true 1
#define false 0
typedef struct {
    int x, y, dis;
}pt;

pt m_queue[MAX];
int head = 0, tail = 0;
int is_empty() {
    if (head == tail) {
        return true;
    }
    return false;
}

void pop() {
    head++;
}

void push(pt tmp) {
    m_queue[tail++] = tmp;
}

pt front() {
    return m_queue[head];
}

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
        head = tail = 0;

        start_x = in_tmp[0] - '1';
        start_y = in_tmp[2] - '1';
        final_x = in_tmp[4] - '1';
        final_y = in_tmp[6] - '1';

        tmp_pt.x = start_x; tmp_pt.y = start_y; tmp_pt.dis = 0;
        push(tmp_pt);
        is_visit[start_x][start_y] = 1;
        while (!is_empty()) {
            tmp_pt = front(); 
            pop();
            if (tmp_pt.x==final_x && tmp_pt.y==final_y) {
                printf("To get from (%c,%c) to (%c,%c) takes %d knight moves.\n", start_x+'1', start_y+'1', final_x+'1', final_y+'1', tmp_pt.dis); 
                break;
            }
            for (i = 0; i < 8; i++) {
                tmp_in_pt.x = tmp_pt.x+move[i][0];
                tmp_in_pt.y = tmp_pt.y+move[i][1];
                tmp_in_pt.dis = tmp_pt.dis;
                if (tmp_in_pt.x>=0&&tmp_in_pt.x<8 && tmp_in_pt.y>=0&&tmp_in_pt.y<8 && is_visit[tmp_in_pt.x][tmp_in_pt.y]==0) {
                    is_visit[tmp_in_pt.x][tmp_in_pt.y] = 1;
                    tmp_in_pt.dis++;
                    push(tmp_in_pt);
                }
            }
        }
    }
    return 0;
}
