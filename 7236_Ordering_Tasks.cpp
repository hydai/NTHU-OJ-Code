#include <stdio.h>
#include <string.h>
#include <utility>
#include <list>

using namespace std;

int cmp(pair <int, int> s1, pair <int, int> s2)
{
    if (s1.first < s2.first) {
        return true;
    }
    return false;
}
int n, m, arr[100+5];
list <pair<int, int> > List;

int main(int argc, char *argv[])
{
    pair <int, int> tmp;
    bool first;
    while (~scanf("%d%d", &n, &m)) {
        if (!n && !m)
            break;
        memset(arr, 0, sizeof(arr));
        first = true;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &tmp.first, &tmp.second);
            arr[tmp.second]++;
            List.push_front(tmp);
        }
        List.sort(cmp);
        while(!List.empty()) {
            for (int i = 1; i <= n; i++) {
                if (arr[i]==0) {
                    if(!first)
                        putchar(32);
                    else {
                        first = false;
                    }
                    arr[i] = -1;
                    printf("%d", i);
                }
            }
            do {
                tmp = List.front(); List.pop_front();
                arr[tmp.second]--;
            }while(tmp.first == List.front().first);
        }
            for (int i = 1; i <= n; i++) {
                if (arr[i]==0) {
                    if(!first)
                        putchar(32);
                    else {
                        first = false;
                    }
                    arr[i] = -1;
                    printf("%d", i);
                }
            }
        putchar(10);
    }
    return 0;
}
