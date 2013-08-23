#include <stdio.h>

int main(int argc, char *argv[])
{
    int n, a, f, i, j;

    scanf("%d", &n);
    while (n > 0) {
        scanf("%d%d", &a, &f);
        
        n--;
        while (f > 0) {
            f--;
            for (i = 1; i <= a; i++) {
                for (j = 0; j < i; j++) {
                    printf("%d", i);
                }
                printf("\n");
            }
            
            for (i = a-1; i > 0; i--) {
                for (j = 0; j < i; j++) {
                    printf("%d", i);
                }
                printf("\n");
            }
            if (!((n == 0) && (f == 0))) {
                printf("\n");
            }
        }
        
    }
    return 0;
}
