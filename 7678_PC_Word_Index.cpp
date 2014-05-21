#include <cstdio>
#include <string>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    map<string, int> M[5];
    for (int i = 'a'; i <= 'z'; i++) {
        M[0][i] = i - 'a' + 1;
    }
    for (int i = 1; i < 5; i++) {
        map<string, int>::iterator iter = M[i-1].begin();
        for (; iter != M[i-1].end(); iter++) {
            for (int j = (iter->first)[i-1]; j <= 'z'; j++) {

            }
        }
    }
    return 0;
}
