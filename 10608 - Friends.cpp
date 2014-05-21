#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <list>
using namespace std;
int N, M, big;
vector<int> society[30000+5];
bool visit[30000+5];

int trace(int, int);
int main()
{
    int test;
    scanf("%d", &test);
    while(test--){
        scanf("%d %d", &N, &M);
        memset(visit, false, sizeof(visit));
        for(int i=0 ; i<30004 ; i++)
            society[i].clear();
        int a, b;
        for(int i=0 ; i<M ; i++){
            scanf("%d %d", &a, &b);
            society[a].push_back(b);
            society[b].push_back(a);
        }
        big=0;
        for(int i=1 ; i<=N ; i++){
            if(!visit[i])
                visit[i] = true, big = max(big, trace(i,1));
        }
        printf("%d\n", big);
    }
    return 0;
}

int trace(int cur, int people)
{
    int temp;
    for(int i=0 ; i<society[cur].size() ; i++){
        if(!visit[society[cur][i]]){
            visit[society[cur][i]] = true;
            temp = trace(society[cur][i], people+1);
            people = max(temp, people);
        }
    }
    return people;
}
