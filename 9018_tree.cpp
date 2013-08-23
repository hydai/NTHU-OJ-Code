#include <cstdio>
#include <cstring>
#include <stack>

#define MAX 1050
using namespace std;
stack<int> m_stack;
bool tree[MAX][MAX];

int main(int argc, char *argv[])
{
    int n, a, b, root, i, j;
    int flag;
    
    while (~scanf("%d", &n)&&n) {
        memset(tree, 0, sizeof(tree));
        flag = 0;
        while (n--) {
            scanf("%d%d", &a, &b);
            tree[a][b] = 1;
        }
        scanf("%d", &root);
        m_stack.push(root);
        while (!m_stack.empty())
        {
            i = m_stack.top();m_stack.pop();
            if (flag++) {
                putchar(' ');
            }
            printf("%d", i);
            for (j = 1000; j > 0; j--) {
                if (tree[i][j]==1) {
                    m_stack.push(j);
                }
            }
        }
        putchar('\n');
    }
    return 0;
}
