#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int MAX = 1000000;
typedef struct A{
    int y,dis;
    A(int _y,int _dis){
        y = _y, dis = _dis;
    }
}AA;
vector <AA> v[10];
int d[10],in[10],pre[10];

void backtrack(int x){
    if(x==-1)return ;
    backtrack(pre[x]);
    printf("%d ",x);
}

int main()
{
for(int N,M;scanf(" %d %d",&N,&M)==2;){
    for(int n=0;n<N;n++)
        v[n].clear(), d[n] = MAX, in[n] = 0, pre[n] = -1;  
    for(int m=0,a,b,c;m<M;m++){
        scanf(" %d %d %d",&a,&b,&c);
        v[a].push_back(A(b,c));
        v[b].push_back(A(a,c));
    }
    d[0] = 0;
    queue <int> q;
    q.push(0);
    while(!q.empty()){
        int x = q.front();q.pop();
        in[x] = 0;

        for(int i=0;i<v[x].size();i++){
            int y = v[x][i].y, dis = v[x][i].dis;
            if(d[x] + dis < d[y]) {
                d[y] = d[x] + dis;
                pre[y] = x;
                if(in[y]==0){
                    in[y] = 1;
                    q.push(y);
                }
            }
        }
    }
    for(int n=1;n<N;n++)
        printf("0 -> %d : %d\n",n,d[n]);
    backtrack(3);
    printf("\n");
}

return 0;
}
