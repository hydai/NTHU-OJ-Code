#include <cstdio>
#include <cstring>
#include <queue>

#define LEN 30

using namespace std;

struct pt {
    int x, y, z, dis;
};

queue <pt> m_queue;
bool is_visit[LEN][LEN][LEN];

int move[6][3] = {
    {1,0,0},
    {-1,0,0},
    {0,1,0},
    {0,-1,0},
    {0,0,1},
    {0,0,-1}
};

int main(int argc, char *argv[])
{
    int l, r, c, flag, start_x, start_y, start_z, final_x, final_y, final_z;
    char tmp_in[50];
    pt tmp_pt, tmp_in_pt;
    while (~scanf("%d%d%d", &l, &r, &c)&&l&&r&&c) {
        getchar();
        memset(is_visit, 0, sizeof(is_visit));
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                gets(tmp_in);
                for (int k = 0; k < c; k++)
                    if (tmp_in[k]=='S') {
                        start_x = i; start_y = j; start_z = k;
                        is_visit[i][j][k] = 1;
                    }
                    else if (tmp_in[k]=='E') {
                        final_x = i; final_y = j; final_z = k;
                    }
                    else if (tmp_in[k]=='#') {
                        is_visit[i][j][k] = 1;
                    }
                    else {}
            }
            getchar();
        }
        /*
        for (int i = 0; i<l;i++) {
            for (int j = 0; j < r; j++)
            {
                for (int k = 0; k < c; k++)
                    printf("%c", (is_visit[i][j][k])?'#':'.');
                putchar('\n');
            }
            putchar('\n');
        }
        printf("######################\n");
        */
        while (!m_queue.empty()) {
            m_queue.pop();
        }
        flag = 0;
        tmp_pt.x = start_x; tmp_pt.y = start_y; tmp_pt.z = start_z; tmp_pt.dis = 0;
        m_queue.push(tmp_pt);
        while (!m_queue.empty()) {
            tmp_pt = m_queue.front(); m_queue.pop();
            if (tmp_pt.x==final_x&&tmp_pt.y==final_y&&tmp_pt.z==final_z) {
                printf("Escaped in %d minute(s).\n", tmp_pt.dis);
                flag = 1;
                break;
            }
            for (int i = 0; i < 6; i++) {
                tmp_in_pt.x = tmp_pt.x+move[i][0]; 
                tmp_in_pt.y = tmp_pt.y+move[i][1]; 
                tmp_in_pt.z = tmp_pt.z+move[i][2]; 
                tmp_in_pt.dis = tmp_pt.dis;
                if (tmp_in_pt.x>=0&&tmp_in_pt.x<l&&tmp_in_pt.y>=0&&tmp_in_pt.y<r&&tmp_in_pt.z>=0&&tmp_in_pt.z<c&&
                    is_visit[tmp_in_pt.x][tmp_in_pt.y][tmp_in_pt.z]==0) {
                    is_visit[tmp_in_pt.x][tmp_in_pt.y][tmp_in_pt.z] = 1;
                    tmp_in_pt.dis++;
                    m_queue.push(tmp_in_pt);
                }
            }
        }
        if (!flag) {
            printf("Trapped!\n");
        }
    }
    return 0;
}
