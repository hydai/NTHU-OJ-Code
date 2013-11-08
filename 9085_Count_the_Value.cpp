#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<char, int>a, pair<char, int>b) {
    if (a.second < b.second) {
        return false;
    }
    else if (a.second == b.second && a.first>b.first) {
        return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    char tmp;
    int List[26] = {0};
    vector<pair<char, int> > Vec;

    while ((tmp = getchar()) != EOF) {
        if (tmp >= 'a' && tmp <= 'z') {
            List[tmp-'a'] += (tmp-'a'+1);
        }
    }
    for (int i = 0; i < 26; i++) {
        if (List[i]) {
            Vec.push_back(pair<char, int>(i+'a', List[i]));
        }
    }
    sort(Vec.begin(), Vec.end(), cmp);
    for (vector<pair<char, int> >::iterator it = Vec.begin(); it != Vec.end(); it++) {
        printf("%c %d\n", it->first, it->second);
    }

    return 0;
}
