#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool Rule(string A, string B)
{
    return (A+B > B+A);
}

int main(int argc, char *argv[])
{
    char input[10];
    int N;
    while (~scanf("%d", &N)) {
        vector <string> List;
        while (N--) {
            scanf("%s", input);
            string tmp(input);
            List.push_back(tmp);
        }
        sort(List.begin(), List.end(), Rule);
        for(vector<string>::iterator it = List.begin(); it != List.end(); ++it) {
            printf("%s", it->c_str());
        }
        putchar('\n');
    }

    return 0;
}
