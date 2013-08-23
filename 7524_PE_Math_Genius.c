#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    char unuse[1000];
    int in_p, in_b, in_final, first, i, half, tmp;
    int ans_b[33000];

    while (~scanf("%d", &in_b)) {
        memset(ans_b, 0, sizeof(ans_b));
        in_final = 1, first = 1;
        if (in_b==0) {
            break;
        }
        do {
            scanf("%d", &in_p);
            in_final *= pow(in_b, in_p);
        } while (scanf("%d", &in_b) && in_b!=0);
        in_final--;
        tmp = in_final;
        half = sqrt(in_final);
        gets(unuse);
        for (i = 2; i <= half; i++) {
            while (tmp%i==0) {
                tmp/=i;
                ans_b[i]++;
            }
        }
        if (tmp>=half) {
            ans_b[tmp]=1;
        }
        for (i = 32999; i > 1; i--) {
            
            if (ans_b[i]) {
                if (first) {
                    first = 0;
                }
                else {
                    printf(" ");
                }
                printf("%d %d", i, ans_b[i]);
            }
        }
        putchar('\n');
    }
    return 0;
}
