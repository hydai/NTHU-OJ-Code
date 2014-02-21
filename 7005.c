#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct AA {
    (struct AA*) nextLevel[10];
    int selfValue;
};

int main(int argc, char *argv[])
{
    int i, t, n, ans;
    long long int num;
    struct AA * first[10];
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        while (n--) {
            int id = 0, arr[10] = 0;
            scanf("%lld", &num);
            while (num) {
                arr[id++] = num%10;
                num /= 10;
            }
        }
    }

    if (ans) {
        puts("YES");
    }
    else {
        puts("NO");
    }

    return 0;
}
