/*
 * flow
 * answer = flow + remainder part of uncover node
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;


int s[1050][1050],pre[1050],st,ed;
char graph[50][50];
bool stop;
void dfs(int v)
{
    for(int i=st;i<=ed && stop;i++)
        if(s[v][i] && pre[i]==-1){
            pre[i]=v;
            if(i==ed)
                stop=false;
            else
                dfs(i);
        }
}
int flow()
{
    int i,j,k,ans=0;
    while(1){
        memset(pre,-1,sizeof(pre));
        stop=true;
        dfs(0);
        if(stop)
            return ans;
        int mini = 1<<29;
        for(i=ed;i!=st;i=pre[i])
            mini = min(mini,s[pre[i]][i]);
        ans+=mini;
        for(i=ed;i!=st;i=pre[i]){
            s[pre[i]][i]-=mini;
            s[i][pre[i]]+=mini;
            graph[pre[i]/10][pre[i]%10] = 'o';
        }
    }
}

int main(int argc, char *argv[])
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int h, w, numOfNode = 0, answer;
        scanf("%d%d", &h, &w);
        memset(graph, '\0', sizeof(graph));
        for (int i = 1; i <= h; i++) {
            scanf("%s", graph[i]);
        }
        st = 0; ed = 1000;
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= h; i++) {
            for (int j = 0; j < w; j++) {
                if (graph[i][j] == '*') {
                    numOfNode++;
                }
                if ((i+j)%2==1 && graph[i][j] == '*') {
                    int origin = i*10+j;
                    s[0][origin] = 1;
                    if ((i-1) >= 1 && graph[i-1][j] == '*') {
                        s[origin][(i-1)*10+j] = 1;
                        s[(i-1)*10+j][1000] = 1;
                    }
                    if ((i+1) <= h && graph[i+1][j] == '*') {
                        s[origin][(i+1)*10+j] = 1;
                        s[(i+1)*10+j][1000] = 1;
                    }
                    if ((j-1) >= 0 && graph[i][j-1] == '*') {
                        s[origin][i*10+j-1] = 1;
                        s[i*10+j-1][1000] = 1;
                    }
                    if ((j+1) < w && graph[i][j+1] == '*') {
                        s[origin][i*10+j+1] = 1;
                        s[i*10+j+1][1000] = 1;
                    }
                }
            }
        }
        answer = flow();
        for (int i = 1; i <= h; i++) {
            for (int j = 0; j < w; j++) {
                if (graph[i][j]=='*') {
                    answer++;
                }
            }
            
        }
        //printf("flow = %d\n", flow());
        //printf("numOfNode = %d\n", numOfNode);
        //printf("answer = %d\n", answer);
        
        printf("%d\n", answer);
    }
    return 0;
}
