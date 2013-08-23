#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[])
{
    string input[55], temp;
    char tmp[55];
    int cn, i, j;
    while (~scanf("%d", &cn) && cn)
    {
        for (i = 0; i < cn; i++) {
            scanf("%s", tmp);
            input[i] = string(tmp);
        }
        for (i = 0; i < cn; i++) {
            for (j = i+1; j < cn; j++) {
                if (input[i]+input[j]<input[j]+input[i]) {
                    temp = input[j]; input[j] = input[i]; input[i] = temp;
                }
            }
        }

        for (i = 0; i < cn; i++) {
            printf("%s", input[i].c_str());
        }
        putchar(10);
    }
    return 0;
}
