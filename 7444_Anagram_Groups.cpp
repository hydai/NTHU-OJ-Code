#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
vector<string> Vec[10000+500];

bool cmp(const vector<string> &a, const vector<string> &b) {
    if (a.size() != b.size()) {
        return a.size() > b.size();
    }
    else if (a.size() == b.size()) {
        return a[0] < b[0];
    }
}

int main(int argc, char *argv[])
{
    string tmpIn, tmp;
    char buffer[10000];
    map<string, int> Map;
    Map.clear();
    int id = 0;
    while (gets(buffer)) {
        tmpIn = (string)buffer;
        tmp = tmpIn;
        sort(tmp.begin(), tmp.end());
        
        if (Map.find(tmp) == Map.end()) {
            Vec[id].push_back(tmpIn);
            Map[tmp] = id++;
        }
        else {
            Vec[Map[tmp]].push_back(tmpIn);
        }
    }
    for (int i = 0; i < id; i++) {
        sort(Vec[i].begin(), Vec[i].end());
    }
    sort(Vec, Vec+id, cmp);
    id = (id > 5)?5:id;
    for (int i = 0; i < id; i++) {
        int sz = (int)Vec[i].size();
        printf("Group of size %d: ", sz);
        tmp = Vec[i].at(0);
        printf("%s ", tmp.c_str());
        for (int j = 1; j < sz; j++) {
            tmpIn = Vec[i].at(j);
            if (tmp != tmpIn) {
                tmp = tmpIn;
                printf("%s ", tmpIn.c_str());
            }
        }
        printf(".\n");
    }
    return 0;
}
