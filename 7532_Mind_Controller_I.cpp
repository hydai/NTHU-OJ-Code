#include <cstdio>
#include <queue>

using namespace std;
queue <int> m_queue;

void rec(int n)
{
    if (n<=3) {
        m_queue.push(n);return;
    }
    else if (n%2==0) {
        rec(n/2-1);
        rec(n/2+1);
    }
    else {
        rec((n-1)/2);
        rec((n+1)/2);
    }
}

int main(int argc, char *argv[])
{
    int input;
    while (~scanf("%d", &input)) {
        rec(input);
        while (!m_queue.empty()) {
            putchar(m_queue.front()+'0');
            m_queue.pop();
        }
        putchar(10);
    }
    return 0;
}
