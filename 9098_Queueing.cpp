#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
struct Name {
    char value[15];
};

int main(int argc, char *argv[])
{
    queue <Name> Queue;
    char cmd[10];
    Name tmp;
    while (~scanf("%s", cmd)) {
        if (cmd[1] == 'u') {
            scanf("%s", tmp.value);
            Queue.push(tmp);
        }
        else if (cmd[1] == 'o') {
            if (!Queue.empty()) {
                Queue.pop();
            }
        }
        else {
            if (!Queue.empty()) {
                printf("%s\n", Queue.front().value);
            }
            else {
                printf("empty\n");
            }
        }
    }
    return 0;
}

