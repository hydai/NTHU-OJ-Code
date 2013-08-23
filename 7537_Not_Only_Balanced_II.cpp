#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

#define MAX 2050
stack <char> m_stack;
queue <int> m_queue;
char input[MAX];

int main()
{
    int index, len, i, first;
    bool flag;
    while(gets(input)!=NULL)
    {
        len = strlen(input);index = 0;flag = true;first = 0;
        while(!m_queue.empty())m_queue.pop();
        while(!m_stack.empty())m_stack.pop();
        if (len == 0)
        {
            printf("\n");
            continue;
        }
        for (i = 0;i < len; i++)
        {
            if (input[i]!='(' && input[i]!=')')continue;
            if (input[i]=='(')
            {
                index++;
                m_queue.push(index);
                m_stack.push(input[i]);
            }
            else
            {
                if (m_stack.empty() || m_stack.top()!='(')
                {flag = false;break;}
                else
                {
                    m_stack.pop();
                    index--;
                }
            }
        }
        if (!m_stack.empty())
            flag = false;
        if (flag)
        {
            while (!m_queue.empty()){
                if(first++)putchar(' ');
                printf("%d", m_queue.front());
                m_queue.pop();
            }
            putchar(10);
        }
        else
        {
            printf("Invalid\n");
        }
    }
    return 0;
}
