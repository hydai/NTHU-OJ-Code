#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 2000
int main(int argc, char *argv[])
{
    int n, i, l, a[SIZE], b[SIZE], c[SIZE];
    int len, shift[3], shift_id;
    char o[SIZE];
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &l);
        for (i = 0; i < l ;i++) {
            scanf("%d", &a[i]);
        }
        for (i = 0; i < l ;i++) {
            scanf("%d", &b[i]);
        }
        scanf("%s", o);
        len = strlen(o);
        shift_id = 0;
        shift[0] = shift[1] = shift[2] = 0;
        for (i = 0; i < len && shift_id < 3; i++) {
            if (o[i] == '1') {
                shift_id++;
            }
            else {
                shift[shift_id]++;
            }
        }
        for (i = 0; i < l; i++) {
            c[(i+shift[2])%l] = a[(i+shift[0])%l] + b[(i+shift[1])%l];
        }
        printf("%d", c[0]);
        for (i = 1; i < l; i++) {
            printf(" %d", c[i]);
        }
        printf("\n");
    }
    return 0;
}
