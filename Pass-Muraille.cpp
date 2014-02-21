#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
struct AA {
    int st, ed, x, len;
    bool operator< (const AA right) const {
        return len < right.len;
    }
};

void Swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main(int argc, char *argv[])
{
    int t, n, k, x1, x2, y1, y2;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        int ctArr[101] = {0};
        map <int, vector<AA> > M;
        M.clear();
        for (int i = 0; i < n; i++) {
            AA tmp;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if (x1 > x2) {
                Swap(&x1, &x2);
            }
            for (int j = x1; j <= x2; j++) {
                ctArr[j]++;
            }
            tmp.st = x1; tmp.ed = x2; tmp.x = y1; tmp.len = (x2 - x1)+1;
            if (M.find(x1) != M.end()) {
                M[x1].push_back(tmp);
            }
            else {
                vector<AA> tmpAA;
                tmpAA.push_back(tmp);
                M[x1] = tmpAA;
            }
        }
        int answer = 0;
        for (int i = 0; i < 101; i++) {
            while (ctArr[i] > k) {
                if (M.find(i) == M.end()) {
                    break;
                }
                vector<AA> tmp = M[i];
                sort(tmp.begin(), tmp.end());
                AA take = tmp[0];
                printf("### %d\n", take.len);
                for (int j = take.st; j <= take.ed; j++) {
                    ctArr[j]--;
                }
                answer++;
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}
