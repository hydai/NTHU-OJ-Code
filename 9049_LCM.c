#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    int n, a, b, n_a, n_b;

    scanf("%d", &n);
    while (n > 0) {
        scanf("%d%d", &a, &b);
        n_a = a;
        n_b = b;
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
        n_a *= (n_b/b);
        printf("%d\n", n_a);
        n--;
    }
    return 0;
}
