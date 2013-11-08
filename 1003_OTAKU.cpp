#define SLOW
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    int N, M, K;
#ifdef SLOW
    string input;
#else
    char input[20];
#endif
    while (~scanf("%d%d", &N, &M)) {
        map<string, int> Map;
        while (N--) {
#ifdef SLOW
            cin >> input;
            Map[input] = 1;
#else
            scanf("%s", input);
            Map[(string)(input)] = 1;
#endif
        }
        while (M--) {
            int count = 0;
            scanf("%d", &K);
            for (int i = 0; i < K; i++) {
#ifdef SLOW
                cin >> input;
                //if (Map[input]) {
                if (Map.find(input)!=Map.end()) {
                    count++;
                }
#else
                scanf("%s", input);
                if (Map[(string)(input)]) {
                    count++;
                }
#endif
            }
            if (count > K/2) {
                putchar('Y');
            }
            else {
                putchar('N');
            }
            putchar(10);
        }
    }
    return 0;
}
