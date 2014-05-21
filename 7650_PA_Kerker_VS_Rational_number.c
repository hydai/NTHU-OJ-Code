#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char str[128];
    int ct = 0, t;
    scanf("%d", &t);
    getchar();
    while (t--) {
        char A[128], B[128], *ptr, *ans;
        int a = 0, b = 0, flag = 0;
        if (ct++) {
            gets(str);
        }
        gets(A);gets(str);gets(B);
        ptr = A;
        ans = str;
        while (*ptr != '\0') {
            if (*ptr == ' ' || *ptr == '-') {
                ptr++;
                continue;
            }
            if (*ptr == '0' && flag == 0) {
                ptr++;
                continue;
            }
            else {
                flag = 1;
            }
            *ans = *ptr;
            ans++;
            ptr++;
        }
        *ans = '\0';
        printf("%s", (strlen(str) > 0)?str:"0");
        ptr = B;
        ans = str;
        flag = 0;
        while (*ptr != '\0') {
            if (*ptr == ' ' || *ptr == '-') {
                ptr++;
                continue;
            }
            if (*ptr == '0' && flag == 0) {
                ptr++;
                continue;
            }
            else {
                flag = 1;
            }
            *ans = *ptr;
            ans++;
            ptr++;
        }
        *ans = '\0';
        printf("/%s\n", (strlen(str) > 0)?str:"0");
    }
    return 0;
}
