#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int t, len, n, i, half, max, min, tmp;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &len, &n);
        max = 0;
        min = 0;
        half = len/2;
        for (i = 0; i < n; i++) {
            scanf("%d", &tmp);
            if (tmp<half) {
                min = (min>tmp)?min:tmp;
            }
            else {
                min = (min>len-tmp)?min:(len-tmp);
            }
            if (tmp<half) {
                max = (max>len-tmp)?max:(len-tmp);
            }
            else {
                max = (max>tmp)?max:tmp;
            }
        }
        printf("%d %d\n", min, max);
    }
    return 0;
}
