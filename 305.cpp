#include <cstdio>
#include <cstdlib>
#include <cstring>
#define SIZE 14
int ans[SIZE];
void solve(int x);
int main(int argc, char *argv[])
{
int input;
memset(ans, -1, sizeof(ans));
while (~scanf("%d", &input) && input) {
    if (ans[input] == -1) {
        solve(input);
    }
    printf("%d\n", ans[input]);
}
return 0;
}

void solve(int x) {
    int minAns = 0, tmp = 0;
    while (minAns == 0) {
        tmp++;
        bool isRight = true;
        int arr[26] = {0}, index = -1, badCt = x;
        while (badCt) {
            int runtime = (tmp%(x + badCt))?(tmp%(x + badCt)):(x+badCt);
            for (int i = 0; i < runtime; i++) {
                index = (index+1) % (x << 1);
                if (arr[index] == 1) {
                    i--;
                }
            }
            if (index >= 0 && index < x) {
                isRight = false;
                break;
            }
            arr[index] = 1;
            badCt--;
        }
        if (isRight) {
            minAns = tmp;
        }
    }
    ans[x] = minAns;
}
