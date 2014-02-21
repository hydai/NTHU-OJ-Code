#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
    int n, a, b, count = 0;
    map<int, int> M;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &b);
        if (M.find(b) == M.end()) M[b] = a;
        else M[b] += a;
    }
    for (map<int, int>::iterator iter = M.begin(); iter != M.end(); iter++)
        if (iter->second != 0) printf("%d %d\n", iter->second, iter->first), count++;
    if (count == 0) printf("0\n");
    return 0;
}
