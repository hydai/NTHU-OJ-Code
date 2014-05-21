#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <vector>
#include <queue>
using namespace std;

vector<int> S;
int pre[128] = {0}, in[128] = {0};
void backtrack(int x){
    if(x==-1)return ;
    backtrack(pre[x]);
    S.push_back(x);
}
int main(int argc, char *argv[])
{
    int n, ct = 1;
    while (~scanf("%d", &n) && n != -1) {
        printf("Case %d:\n", ct++);
        vector<int> V[128];
        S.clear();
        int st, ed;
        long long target;
        long long dis[128];
        char str[2][10];
        for (int i = 0; i < n; i++) {
            scanf("%s%s", str[0], str[1]);
            V[str[0][0]].push_back(str[1][0]);
            V[str[1][0]].push_back(str[0][0]);
        }
        scanf("%lld%s%s", &target, str[0], str[1]);
        st = str[0][0]; ed = str[1][0];
        // Skip special case
        if (n == 0 || st == ed) {
            printf("%lld\n", target);
            printf("%c\n", st);
            continue;
        }
        // Reset for running
        memset(pre, -1, sizeof(pre));
        memset(in, 0, sizeof(in));
        for (int i = 0; i < 128; i++) {
            dis[i] = 99999999999LL;
        }
        dis[ed] = target;
        queue<int> Q;
        Q.push(ed);
        while (!Q.empty()) {
            int cur = Q.front(); Q.pop();
            in[cur] = 0;

            for (int i = 0; i < V[cur].size(); i++) {
                char ch = (char)V[cur][i];
                long long tmp = 0;
                if (isupper(cur)) {
                    if (dis[cur] % 19 == 0) {
                        tmp = dis[cur]*20/19;
                    } else {
                        tmp = dis[cur]*20/19+1;
                    }
                } else {
                    tmp = dis[cur]+1;
                }
                if (tmp < dis[ch]) {
                    dis[ch] = tmp;
                    pre[ch] = cur;
                    if (!in[ch]) {
                        Q.push(ch);
                    }
                } else if (tmp == dis[ch]) {
                    if (cur < pre[ch]) {
                        pre[ch] = cur;
                        if (!in[ch]) {
                            Q.push(ch);
                        }
                    }
                }
            }
        }
        printf("%lld\n", dis[st]);
        backtrack(st);
        int index = S.size()-1;
        printf("%c", S[index--]);
        for (;index >= 0; index--) {
            printf("-%c", S[index]);
        }
        putchar(10);
    }
    return 0;
}
