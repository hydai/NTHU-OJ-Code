#include <cstdio>
#include <cstring>
#include <queue>

#define MAX 1050
using namespace std;
bool connect[MAX][MAX];
queue <int> m_queue;
int main(int argc, char *argv[])
{
    int i, j, t, first = 0, n, root, tmp_i, tmp_j;
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        memset(connect, 0, sizeof(connect));
        if (first++) {
            putchar(10);
        }
        printf("Case %d: ", i+1);
        scanf("%d%d", &n, &root);n--;
        while (n--) {
            scanf("%d%d", &tmp_i, &tmp_j);
            connect[tmp_i][tmp_j] = connect[tmp_j][tmp_i] = 1;
        }
        m_queue.push(root);
        printf("%d", root);
        while (!m_queue.empty()) {
            root = m_queue.front();m_queue.pop();
            for (j = 0; j < MAX; j++) {
                if (connect[root][j]) {
                    connect[root][j] = connect[j][root] = 0;
                    printf(" %d", j);
                    m_queue.push(j);
                }
            }
        }
        putchar(10);
    }
    
    return 0;
}

