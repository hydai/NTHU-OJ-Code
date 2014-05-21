#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
bool cmp(const string a, const string b) {
    if (a.size() < b.size())
        return false;
    else if (a.size() > b.size()) {
        return true;
    }
    return a > b;
}
string S[10000+10];
int main(int argc, char *argv[])
{
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    sort(S, S+n, cmp);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        cin >> n;
        cout << S[n-1] << endl;
    }
    return 0;
}

