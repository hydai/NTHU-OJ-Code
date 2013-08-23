#include <cstdio>
#include <list>
#include <algorithm>

using namespace std;

#define LEN 1000000+50

int M[LEN], N[LEN];

int main(int argc, char *argv[])
{
    int m, n, index_m, index_n, first;
    list<int> List;
    while (~scanf("%d", &m)) {
        first = 0;
        while (!List.empty()) {
            List.pop_front();
        }
        if (m==0) {
            break;
        }
        index_m = index_n = 0;
        for (int i = 0; i < m; i++) {
            scanf("%d", &M[i]);
        }
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &N[i]);
        }
        sort(M, M+m);
        sort(N, N+n);
        while (index_m != m && index_n != n) {
            if (M[index_m] < N[index_n]) {
                ++index_m;
            }
            else if (M[index_m] > N[index_n]) {
                ++index_n;
            }
            else {
                List.push_back(M[index_m]);
                ++index_m, ++index_n;
            }
        }
        if (List.empty()) {
            puts("empty");
        }
        else {
            while (!List.empty()) {
                if (first++) {
                    putchar(32);
                }
                printf("%d", List.front());
                List.pop_front();
            }
            putchar(10);
        }
    }
    return 0;
}
