#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;
int N, L;

int getValue(char *str) {
    int V[4] = {0}, ans = 0;
    for (int i = 0; i < L; i++) {
        if (str[i] == 'A') {
            ans += V[1]+V[2]+V[3];
            V[0]++;
        }
        else if (str[i] == 'C') {
            ans += V[2]+V[3];
            V[1]++;
        }
        else if (str[i] == 'G') {
            ans += V[3];
            V[2]++;
        }
        else if (str[i] == 'T') {
            V[3]++;
        }
    }
    return ans;
}

bool cmp(pair<string, int> a, pair<string, int> b) {
    if (a.second < b.second) {
        return true;
    }
    else if (a.second == b.second && a.first > b.first) {
        return true;
    }
    return false;
}

int main(int argc, char *argv[])
{
    while (~scanf("%d%d", &N, &L)) {
        char tmp[20];
        vector<pair<string, int> > Vec;
        for (int i = 0; i < N; i++) {
            scanf("%s", tmp);
            Vec.push_back(pair<string, int>((string)(tmp), getValue(tmp)));
        }
        sort(Vec.begin(), Vec.end(), cmp);
        for (vector<pair<string, int> >::iterator it = Vec.begin(); it != Vec.end(); it++) {
            printf("%s\n", it->first.c_str());
        }
    }
    return 0;
}
