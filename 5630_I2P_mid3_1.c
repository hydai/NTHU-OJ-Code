#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int T;
    scanf("%d", &T);
    while (T--) {
        int ans = 0, count[128] = {0}, len, i;
        char str[128];
        scanf("%s", str);
        len = strlen(str);
        for (i = 0; i < len; i++) {
            count[str[i]]++;
        }
        for (i = 'A'; i <= 'Z'; i++) {
            ans += ((count[i] > count[i+32])?(count[i]-count[i+32]):(count[i+32]-count[i]));
        }
        printf("%d\n", ans);
    }
    return 0;
}
