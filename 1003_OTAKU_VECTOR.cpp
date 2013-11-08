#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    int N, M, K;
    while (~scanf("%d%d", &N, &M)) {
        string str;
        vector<string> Vec;
        int count = 0;
        while (N--) {
            cin >> str;
            Vec.push_back(str);
        }
        sort(Vec.begin(), Vec.end());
        while (M--) {
            scanf("%d", &K);
            while (K--) {
                cin >> str;
                if (binary_search(Vec.begin(), Vec.end(), str)) {
                    count++;
                }
            }
            if (count > K/2) {
                puts("Y");
            }
            else {
                puts("N");
            }
        }
    }
    return 0;
}
