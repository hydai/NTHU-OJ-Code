#include <stdio.h>
#include <string.h>

#define LEN 1000000+100

char str[LEN];
int shift;

void Rev() {
    int i;
    int len = strlen(str);
    char tmp;
    for (i = 0; i < len/2; i++) {
        tmp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = tmp;
    }

    return ;
}

void EShift() {
    int i;
    int len = strlen(str);
    for (i = 0; i < len; i++) {
        str[i] = 'A' + (str[i] - 'A' + shift)%26;
    }
    return ;
}

void DShift() {
    int i;
    int len = strlen(str);
    for (i = 0; i < len; i++) {
        str[i] = 'A' + (str[i] - 'A' + 260 - shift)%26;
    }
    return ;
}

int main(int argc, char *argv[])
{
    int T, op;
    while (~scanf("%d", &T)) {
        while (T--) {
            scanf("%d%d%s", &op, &shift, str);
            if (op == 1) {
                Rev();
                EShift();
            }
            else {
                DShift();
                Rev();
            }
            printf("%s\n", str);
        }
    }
    return 0;
}
