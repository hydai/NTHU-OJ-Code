#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 200

int main(int argc, char *argv[])
{
    char input[MAX_LEN][MAX_LEN];
    int n, length, output[30];
    scanf("%d", &n);

    while (n) {
        i = 0;
        gets(input[i]);
        if (*input == '*') {
            n--;
            putchar('\n');
            continue;
        }
        
        length = strlen(input);
    }
    return 0;
}
