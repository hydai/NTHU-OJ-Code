#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;
int main(int argc, char *argv[])
{
    char str[1050];
    int N, count = 1;
    scanf("%d", &N);
    getchar();
    while (N--) {
        stack<char> Stack;
        bool flag = true;
        printf("Case %d: ", count++);
        fgets(str, 1050, stdin);
        if (str[0] == '\n') {
            printf("Yes\n");
            continue;
        }
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            if (str[i] == '{' || str[i] == '[' || str[i] == '(' || str[i] == '<') {
                Stack.push(str[i]);
            }
            else if (str[i] == '}') {
                if (!Stack.empty() && Stack.top() == '{') {
                    Stack.pop();
                }
                else {
                    flag = false;
                    break;
                }
            }
            else if (str[i] == ']') {
                if (!Stack.empty() && Stack.top() == '[') {
                    Stack.pop();
                }
                else {
                    flag = false;
                    break;
                }
            }
            else if (str[i] == '>') {
                if (!Stack.empty() && Stack.top() == '<') {
                    Stack.pop();
                }
                else {
                    flag = false;
                    break;
                }
            }
            else if (str[i] == ')') {
                if (!Stack.empty() && Stack.top() == '(') {
                    Stack.pop();
                }
                else {
                    flag = false;
                    break;
                }
            }
        }
        if (!Stack.empty()) {
            flag = false;
        }
        if (flag) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}
