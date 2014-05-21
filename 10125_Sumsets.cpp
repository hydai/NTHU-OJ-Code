#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#define SIZE 1000+100
using namespace std;
int source[SIZE];
int main(int argc, char *argv[])
{
    int n;
    const char noAns[] = "no solution";
    while (~scanf("%d", &n) && n != 0) {
        map <int, vector<pair<int,int> > > M;
        M.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d", &source[i]);
        }
        sort(source, source+n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    int x = source[i] + source[j];
                    if (M.find(x) != M.end()) {
                        M[x].push_back(pair<int,int>(source[i], source[j]));
                    }
                    else {
                        vector<pair<int, int> > tmp;
                        tmp.push_back(pair<int,int>(source[i], source[j]));
                        M[x] = tmp;
                    }
                }
            }
        }
        int Max = -1000000000;
        bool ans = true;;
        map<int, vector<pair<int,int> > >::iterator iter;
        for (int i = n-1; i >= 0 && ans; i--) {
            for (int j = i-1; j >= 0 && ans; j--) {
                int dMc = source[i] - source[j];
                iter = M.find(dMc);
                if (iter == M.end()) {
                    continue;
                }
                else {
                    for (int k = 0; k < (iter->second).size(); k++) {
                        pair<int,int> tmp = (iter->second).at(k);
                        if (source[i] == tmp.first 
                          || source[j] == tmp.first 
                          || source[i] == tmp.second 
                          || source[j] == tmp.second) {
                            continue;
                        }
                        else {
                            Max = source[i];
                            ans = false;
                            break;
                        }
                    }
                }
            }
        }
        if (ans == true) {
            printf("%s\n", noAns);
        }
        else {
            printf("%d\n", Max);
        }
    }
    return 0;
}

