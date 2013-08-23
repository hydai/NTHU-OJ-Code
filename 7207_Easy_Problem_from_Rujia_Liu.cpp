/****************************************************************************
 * 暴力建表解
 * 利用map+pair+find
 * pair <<int, int>, int>
 * pair <<v, k>, local>
 ****************************************************************************/

#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;
#define MAX 1001000

int arr[MAX];
map <pair<int, int>, int> m_map;

int main(int argc, char *argv[])
{
    int n, m, k, v, tmp;
    while (~scanf("%d", &n)) {
        memset(arr, 0, sizeof(arr));
        m_map.clear();
        scanf("%d", &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            arr[tmp]++;
            pair <int, int> in_front (tmp, arr[tmp]);
            pair <pair<int, int>, int> in (in_front, i+1);
            m_map.insert(in);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &k, &v);
            pair <int, int> find_p (v, k);
            printf("%d\n", m_map.find(find_p)->second);
        }
    }
    return 0;
}
