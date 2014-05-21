#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 35000
int djs[SIZE];
int ss[SIZE];
int i;
int find_(int x){
    return (x == djs[x]) ? x : (djs[x] = find_(djs[x]));
}
void init(int n){
    for(i = 0; i <= n; i++)
        djs[i] = i;
    for(i = 0; i <= n; i++)
        ss[i] = 0;
}
void merge_(int a, int b){
    djs[find_(a)] = find_(b);
}
int main(int argc, char *argv[])
{
    int t, m, n, max;
    int a, b;
    scanf("%d", &t);
    while (t--) {
        max = 0;
        scanf("%d%d", &n, &m);
        init(n);
        while (m--) {
            scanf("%d%d", &a, &b);
            merge_(a, b);
        }
        for (i = 0; i <= n; i++) {
            ss[djs[i]]++;
            if (ss[djs[i]] > max) {
                max = ss[djs[i]];
            }
        }
        printf("%d\n", max);
    }
    return 0;
}
