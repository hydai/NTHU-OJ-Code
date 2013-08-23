#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
stack <char> m_stack;
int main(int argc, char *argv[])
{
    char input[2050];
    while (NULL!=gets(input)) {
        int len = strlen(input);
        bool flag = true;
        while (!m_stack.empty()) {
            m_stack.pop();
        }
        for (int i = 0; i < len; i++) {
            if (input[i]=='(') {
                m_stack.push(input[i]);
            }
            else if (input[i]==')') {
                if (m_stack.empty() || m_stack.top()!='(') {flag = false;break;}
                m_stack.pop();
            }
            else if (input[i]=='[') {
                if (!m_stack.empty() && m_stack.top()=='(') {flag = false;break;}
                m_stack.push(input[i]);
            }
            else if (input[i]==']') {
                if (m_stack.empty() || m_stack.top()!='[') {flag = false;break;}
                m_stack.pop();
            }
            else if (input[i]=='{') {
                if (!m_stack.empty() && (m_stack.top()=='(' || m_stack.top()=='[')) {flag = false;break;}
                m_stack.push(input[i]);
            }
            else {
                if (m_stack.empty() || m_stack.top()!='{') {flag = false;break;}
                m_stack.pop();
            }
        }
        if (!m_stack.empty()) {
            flag = false;
        }

        if (flag) {
            printf("Valid\n");
        }
        else {
            printf("Invalid\n");
        }
    }
    return 0;
}
