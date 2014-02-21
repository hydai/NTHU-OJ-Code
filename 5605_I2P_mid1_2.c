#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int i, len, left[128] = {0}, right[128] = {0};
    char str[100];
    scanf("%s", str);
    len = strlen(str);
    for (i = 0; i < len; i++) {
        if (left[str[i]] == 0 || left[str[i]] > i+1) left[str[i]] = i+1;
        if (right[str[i]] < i+1) right[str[i]] = i+1;
    }
    for (i = 'A'; i <= 'Z'; i++) {
        if (left[i] != 0) printf("%c:%d,%d\n", i, left[i], right[i]);
    }
    return 0;
}
