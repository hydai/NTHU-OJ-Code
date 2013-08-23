#include <iostream>
#include <queue>

using namespace std;
struct data {
    char name[20];
    int grade;
};
data tmp;
queue <data> q[101];

int main(int argc, char *argv[])
{
    int n, i;

    while(~scanf("%d", &n))
    {
        while (n--) {
            scanf("%s%d", tmp.name, &tmp.grade);
            q[tmp.grade].push(tmp);
        }

        for (i = 0; i < 101; i++) {
            while (!q[i].empty()) {
                tmp = q[i].front();
                printf("%s %d\n", tmp.name, tmp.grade);
                q[i].pop();
            }
        }
    }
    return 0;
}
