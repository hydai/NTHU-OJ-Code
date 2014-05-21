#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int num[50+5];
long long arr[50+5][20+5];
long long pre[50+5][20+5];
long long Max(long long a, long long b) {
    return (a>b)?a:b;
}
int main(int argc, char *argv[])
{
int n;
int space = 0;
while(~scanf("%d", &n) && (n!=0)) {
    long long tt;
    memset(arr, 0, sizeof(arr));
    memset(pre, 0, sizeof(pre));
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        pre[i][0] = 0;
        for (int j = 1; j <= num[i]; j++) {
            scanf("%lld", &tt);
            arr[i][j] = 10 - tt;
            pre[i][j] = pre[i][j-1] + arr[i][j];
        }
    }
    long long MM = 0;
    long long MAXM = 0;
    vector<long long int> VV[55];
    for (int i = 0; i < n; i++) {
        MM = 0;
        VV[i].clear();
        VV[i].push_back(0);
        for (int j = 0; j <= num[i]; j++) {
            if (pre[i][j] > MM) {
                MM = pre[i][j];
                VV[i].clear();
                VV[i].push_back(j);
            }
            else if (pre[i][j] == MM){
                VV[i].push_back(j);
            }
        }
        MAXM += MM;
    }
    int tat = 0;
    vector<long long int> tmp;
    tmp.clear();
    while(tmp.size() == 0) {
        map<int, int>M;
        sort(VV[tat].begin(), VV[tat].end());
        for (int i = 0; i < VV[tat].size(); i++) {
            M[VV[tat][i]] = 1;
        }
        map<int, int>::iterator iter = M.begin();
        for (int iii = 10; iter!=M.end() && iii > 0 ; iter++) {
            if (iter->first > 0) {
                tmp.push_back(iter->first);
                iii--;
            }
        }
        tat++;
    }
    for (int i = tat; i < n; i++) {
        vector<long long int> tmp2;
        for (int j = 0; j < VV[i].size(); j++) {
            for (int k = 0; k < tmp.size(); k++) {
                if (VV[i][j] + tmp[k] > 0)
                    tmp2.push_back(VV[i][j]+tmp[k]);
            }
        }
        if (tmp2.size() != 0) {
            sort(tmp2.begin(), tmp2.end());
            map<int,int>MM;
            for (int ii = 0; ii < tmp2.size(); ii++) {
                MM[tmp2[ii]] = 1;
            }
            map<int, int>::iterator iter = MM.begin();
            tmp.clear();
            long long t1 = 0;
            for (int ii = 0; ii < 10 && iter != MM.end(); iter++) {
                if (iter->first <= t1) {
                    continue;
                }
                tmp.push_back(iter->first);
                t1 = iter->first;
            }
        }
    }
    if (tmp.size() == 0) {
        tmp.push_back(0);
    }
    if (space++) {
        putchar(10);
    }

    printf("Workyards %d\n", n);
    printf("Maximum profit is %lld.\n", MAXM);
    printf("Number of pruls to buy:");
    for (int i = 0; i < tmp.size(); i++) {
        printf(" %lld", tmp[i]);
    }
    putchar(10);
}
return 0;
}
