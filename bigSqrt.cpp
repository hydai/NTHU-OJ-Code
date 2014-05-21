#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#define SIZE 10000

char str[SIZE];
char ans[SIZE];
int ans_ct = 0;

void addToAns(long long root) {
    char tmp[SIZE];
    sprintf(tmp, "%lld", root);
    char *ptr = tmp;
    while (*ptr != '\0') {
        ans[ans_ct++] = *ptr;
        ptr++;
    }
}

int main(int argc, char *argv[])
{
    while(~scanf("%s", str)) {
        int len = strlen(str);
        int ct = 0;
        long long tmp = 0;
        ans_ct = 0;
        if (len % 2 == 1) {
            tmp = str[ct++] - '0';
        }
        else {
            tmp = (str[ct++] - '0')*10 + str[ct++] - '0';
        }
        while (ct <= len) {
            long long root = (long long)(sqrt(tmp) + 0.001);
            addToAns(root);
            tmp -= (root*root);
            tmp *= 100;
            tmp += str[ct++] - '0';
            tmp *= 10;
            tmp += str[ct++] - '0';
        }
        ans[ans_ct] = '\0';
        printf("%s\n", ans);
    }
    return 0;
}
