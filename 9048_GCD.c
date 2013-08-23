#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    int n, a, b;

    scanf("%d", &n);
    while (n > 0) {
        scanf("%d%d", &a, &b);
        while (a != 0) {
            
            if (a < b) {
                a = a^b;
                b = a^b;
                a = a^b;
            }
            if (b != 0) {
                a = a % b;
            }
        }
        printf("%d\n", b);
        n--;
    }
    return 0;
}
