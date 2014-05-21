#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <list>

using namespace std;
char input[100000];
bool Map[30][30];
int idCt = 0;
map<char, int> idMapping;
map<int, char> mappingId;
list<char> LIST;
void dfs(int st) {
    if (LIST.size() == idCt) {
        list<char>::iterator iter = LIST.begin();
        for (; iter != LIST.end(); iter++) {
            putchar(*iter);
        }
        putchar(10);
        LIST.pop_back();
        return;
    }
    for (int i = 0; i < idCt; i++) {
        if (i != st && !Map[st][i]) {
            Map[st][i] = true;
            LIST.push_back(mappingId[i]);
#ifndef DEBUG
        list<char>::iterator iter = LIST.begin();
        printf("Len======================\n");
        for (; iter != LIST.end(); iter++) {
            putchar(*iter);
        }
        putchar(10);
        printf("/Len======================\n");
#endif
            dfs(i);
            Map[st][i] = false;
        }
    }
}

int main(int argc, char *argv[])
{
    int T = 0;
    while (gets(input) != NULL) {
        idMapping.clear();
        mappingId.clear();
        LIST.clear();
        if (T++) {
            printf("\n");
        }
        idCt = 0;
        int len = strlen(input);
        memset(Map, 0, sizeof(Map));
        for (int i = 0; i < len; i++) {
            if (input[i] != ' ' && idMapping.find(input[i]) == idMapping.end()) {
                mappingId[idCt] = input[i];
                Map[idCt][idCt] = true;
                idMapping[input[i]] = idCt++;
            }
        }
        gets(input);
        len = strlen(input);
        bool isH = true;
        char fi,li;
        for (int i = 0; i < len; i++) {
            if (input[i] != ' ') {
                if (isH) {
                    fi = input[i];
                    isH = false;
                } else {
                    li = input[i];
                    isH = true;
                    Map[idMapping[fi]][idMapping[li]] = true;
                }
            }
        }
#ifndef DEBUG
        map<int, char>::iterator i1 = mappingId.begin();
        printf("mappingId=======================\n");
        for (; i1 != mappingId.end(); i1++) {
            printf("%d %c\n", i1->first, i1->second);
        }
        printf("/mappingId=======================\n");
        printf("Map=======================\n");
        for (int i = 0; i < idCt; i++) {
            for (int j = 0; j < idCt; j++) {
                printf(" %2c", (Map[i][j]?('T'):('F')));
            }
            putchar(10);
        }
        printf("/Map=======================\n");
#endif
        map<char, int>::iterator iter = idMapping.begin();
        for (; iter != idMapping.end(); iter++) {
            printf("St = %c\n", iter->first);
            dfs(idMapping.begin()->second);
        }
    }
    return 0;
}
