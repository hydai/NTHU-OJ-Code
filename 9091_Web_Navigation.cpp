#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

struct url {
    char str[100];
};

int main(int argc, char *argv[])
{
    char CMD[20], URL[100];
    stack<url> Current, Earlier;
    char Home[] = {"http://www.acm.org/"};
    url tmp;

    while (~scanf("%s", CMD)) {
        if (CMD[0] == 'V') {
            while (!Earlier.empty()) {
                Earlier.pop();
            }
            scanf("%s", URL);
            strcpy(tmp.str, URL);
            Current.push(tmp);
            printf("%s\n", URL);
        }
        else if (CMD[0] == 'B') {
            if (!Current.empty()) {
                Earlier.push(Current.top());
                Current.pop();
                if (Current.empty()) {
                    printf("%s\n", Home);
                }
                else {
                    printf("%s\n", Current.top().str);
                }
            }
            else {
                printf("Ignored\n");
            }
        }
        else {
            if (!Earlier.empty()) {
                Current.push(Earlier.top());
                Earlier.pop();
                printf("%s\n", Current.top().str);
            }
            else {
                printf("Ignored\n");
            }
        }
    }

    return 0;
}
