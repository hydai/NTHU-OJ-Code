#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
    string str;
    map <string, int> M;
    while (cin >> str) {
        sort(str.begin(), str.end());
        if (M.find(str) == M.end()) M[str] = 1;
        else M[str]++;
    }
    int Max = 0;
    for (map <string, int>::iterator iter = M.begin(); iter != M.end(); iter++)
        if (Max < iter->second) Max = iter->second;
    cout << Max;
    return 0;
}
