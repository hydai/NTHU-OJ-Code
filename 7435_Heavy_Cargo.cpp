#include <iostream>
#include <string>
#include <map>

#define INF 1000000000

using namespace std;
int road[200+1][200+1];
int max(int a, int b)
{
    return (a>b)?a:b;
}
int min(int a, int b)
{
    return (a<b)?a:b;
}
int main(int argc, char *argv[])
{
    int n, query, ct = 0;
    while (cin >> n >> query) {
        string start, end;
        if (n == 0 && query == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                road[i][j] = (i==j)?0:-INF;
            }
        }
        
        string from, to;
        int tons;
        int id = 0;
        map<string, int> Map; Map.clear();
        cout << "Scenario #" << ++ct << endl;
        for (int i = 0; i < query; i++) {
            cin >> from >> to >> tons;
            if (Map.find(from) == Map.end()) {
                Map[from] = id++;
            }
            if (Map.find(to) == Map.end()) {
                Map[to] = id++;
            }
            road[Map[from]][Map[to]] = tons;
            road[Map[to]][Map[from]] = tons;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    road[i][j] = max(road[i][j], min(road[i][k], road[k][j]));
                }
            }
        }
        
        cin >> start >> end;
        cout << road[Map[start]][Map[end]] << " tons\n\n";
    }

    return 0;
}
