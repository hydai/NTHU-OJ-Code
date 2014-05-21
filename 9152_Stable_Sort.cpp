#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
struct Name {
    char name[15];
};

int main(int argc, char *argv[])
{
    int n;
    while (~scanf("%d", &n)) {
        int score;
        vector<Name> V[101];
        Name tmp;
        for (int i = 0; i < n; i++) {
            scanf("%s%d", tmp.name, &score);
            V[score].push_back(tmp);
        }
        vector<Name>::iterator it;
        for (int i = 0; i < 101; i++) {
            it = V[i].begin();
            while (it != V[i].end()) {
                printf("%s %d\n", it->name, i);
                it++;
            }
        }
    }
    return 0;
}
