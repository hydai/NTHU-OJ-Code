#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i;
    char str[100] = {0};
    for (i = 0; i < 99; i++) {
        str[i] = i;
    }
    printf("%s\n", str);
    return 0;
}
