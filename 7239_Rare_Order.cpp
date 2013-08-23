#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

vector <string> Vec;
int main(int argc, char *argv[])
{
    char tmp[25];
    while(~scanf("%s", tmp))
        if (tmp[0]=='#')
            break;
        else
            Vec.push_back(string(tmp));

    int size = Vec.size();
    string front, back;
    while(size--)
    {

    }
    return 0;
}
