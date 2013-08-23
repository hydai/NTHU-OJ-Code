#include <cstdio>
#include <cstring>
#include <stack>

#define MAX_LEN 1050
using namespace std;
int main(int argc, char *argv[])
{
    int n, i, length;
    int priority[256];
    char tmp_in[MAX_LEN];
    stack <char> m_stack;
    // build priority
    memset(priority, -1, sizeof(priority));
    for (i = 0; i < 10; i++) {
        priority[i+'0'] = 0;
    }
    priority['('] = 1; priority['+'] = priority['-'] = 2; priority['*'] = priority['/'] = 3;
    scanf("%d", &n);
    while (n--) {
        while (!m_stack.empty()) {
            m_stack.pop();
        }
        scanf("%s", tmp_in);
        length = strlen(tmp_in);
        for (i = 0; i < length; i++) {
            if (priority[tmp_in[i]]==0) {
                // 0~9
                putchar(tmp_in[i]);
            }
            else if (priority[tmp_in[i]]==1) {
                // (
                m_stack.push(tmp_in[i]);
            }
            else if (priority[tmp_in[i]]==2 || priority[tmp_in[i]]==3) {
                // +-*/
                while (!m_stack.empty()&&priority[m_stack.top()]>=priority[tmp_in[i]]) {
                    putchar(m_stack.top());m_stack.pop();
                }
                m_stack.push(tmp_in[i]);
            }
            else if (tmp_in[i]==')') {
                while (!m_stack.empty()&&m_stack.top()!='(') {
                    putchar(m_stack.top());m_stack.pop();
                }
                if (m_stack.top()=='(') {
                    m_stack.pop();
                }
            }
        }
        while (!m_stack.empty()) {
            putchar(m_stack.top());m_stack.pop();
        }
        putchar('\n');
    }
    return 0;
}
