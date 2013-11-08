#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
    int N;
    string tmp;
    while (~scanf("%d", &N) && N) {
        map <string, int> Map;
        while (N--) {
            cin >> tmp;
            Map[tmp] = 1;
        }
        for (map<string, int>::iterator it = Map.begin(); it != Map.end(); it++) {
            printf("%s\n", it->first.c_str());
        }
        putchar(10);
    }
    return 0;
}
