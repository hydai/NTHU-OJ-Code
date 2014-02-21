#include <cstdio>
#include <map>
using namespace std;
int main(int argc, char *argv[])
{
    int n, a, b;
    while (~scanf("%d", &n) && n!=0) {
        map<int, int> root, child;
        root.clear(); child.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            if (child.find(a) != child.end())
                child.erase(a), root[a] = 1;
            if (root.find(b) == root.end())
                child[b] = 1;
        }
        scanf("%d", &n);
        printf("%ld\n", child.size());
    }
    return 0;
}
