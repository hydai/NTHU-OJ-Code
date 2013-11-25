#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;
int list[1000000+1000];
int main(int argc, char *argv[])
{
    int T, n;
    scanf("%d", &T);
    while (T--) {
        int st = 0, ed = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &list[i]);
        }
        
        int maxlen = 0;
        int index = 0;
        map<int, int> M;
        queue<int> Q;
        Q.push(list[st]);
        M[list[st]] = 1;
        while (st < n) {
            st++;
            if (M.find(list[st]) != M.end()) {
                while (Q.front()!=list[st]) {
                    M.erase(Q.front());
                    Q.pop();
                    ed++;
                } Q.pop(); ed++;
                M[list[st]] = 1;
                Q.push(list[st]);
            }
            else {
                M[list[st]] = 1;
                Q.push(list[st]);
            }
            maxlen = max(maxlen, (st-ed));
        }
        printf("%d\n", maxlen);
    }
    return 0;
}
