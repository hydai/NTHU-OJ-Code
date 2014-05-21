#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int mv[4][2] = {
    {-1, 0}, // N
    {0, 1}, // E
    {1, 0}, // S
    {0, -1} // W
};
int getDN(char c) {
    if (c == 'N')
        return 0;
    else if (c == 'E')
        return 1;
    else if (c == 'S')
        return 2;
    else
        return 3;
}
int dis[10][10];
pair<int,int> st,ed;
int main(int argc, char *argv[])
{
    string name;
    while(cin >> name) {
        if (name == "END") break;
        cout << name << endl;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                dis[i][j] = 2147483647;
            }
        }
        map< pair< int , int >, vector< pair< int , int > > > M;
        string dir;
        cin >> st.first >> st.second >> dir >> ed.first >> ed.second;
        pair< int , int > tmpP;
        string tmpd;
        while (cin >> tmpP.first) {
            if (tmpP.first == 0) break;
            cin >> tmpP.second;
            if (M.find(tmpP) == M.end()) {
                vector< pair< int , int > > tat; tat.clear();
                M[tmpP] = tat;
            }
            while (cin >> tmpd) {
                if (tmpd == "*") break;
                pair< int , int > tmpNP;
                int dirN = getDN(tmpd[0]);
                for (int i = 1; i < tmpd.size(); i++) {
                    if (tmpd[i] == 'F') {
                        tmpNP.first = tmpP.first + mv[dirN][0];
                        tmpNP.second = tmpP.second + mv[dirN][1];
                        M[tmpP].push_back(tmpNP);
                    } else if (tmpd[i] == 'L') {
                        int tmpDN = (dirN+4-1)%4;
                        tmpNP.first = tmpP.first + mv[tmpDN][0];
                        tmpNP.second = tmpP.second + mv[tmpDN][1];
                        M[tmpP].push_back(tmpNP);
                    } else if (tmpd[i] == 'R') {
                        int tmpDN = (dirN+1)%4;
                        tmpNP.first = tmpP.first + mv[tmpDN][0];
                        tmpNP.second = tmpP.second + mv[tmpDN][1];
                        M[tmpP].push_back(tmpNP);
                    }
                }
            }
            dis[st.first] = 0;
            dis[st.second] = 0;
            spfa();

        }

    }
    return 0;
}
