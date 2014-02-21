#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        while (n > 0 && m > 0) {
            if (n > m) {
                putchar('B');
                putchar('G');    
            }
            else {
                putchar('G');    
                putchar('B');
            }
            n--; m--;
        }
        while (n--) {
            putchar('B');
        }
        while (m--) {
            putchar('G');
        }
        putchar(10);
    }
    return 0;
}
