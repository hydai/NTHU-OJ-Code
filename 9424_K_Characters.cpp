#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int m, arr[128];
string input;
char ans[15];
void dfs(int lv, int aa) {
    if (aa == m) {
        ans[m] = '\0';
        printf("%s\n", ans);
        return;
    }
    if (aa > m || lv >= input.length()) return;
    ans[aa] = input[lv];
    arr[input[lv]]--;
    dfs(lv+1, aa+1);
    arr[input[lv]]++;
    dfs(lv+arr[input[lv]], aa);
}

int main(int argc, char *argv[])
{
    int n;
    scanf("%d", &n);
    while (n--) {
        memset(arr, 0, sizeof(arr));
        string in;
        input="";
        cin >> in >> m;
        sort(in.begin(), in.end());
        for (int i = 0; i < in.length(); i++) {
            if (arr[in[i]] < m) {
                input+=in[i];
                arr[in[i]]++;
            }
        }
        
        dfs(0, 0);
        putchar(10);
    }

    return 0;
}
