#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LEN 100000000

int main(int argc, char *argv[])
{
    int first, time, input, i, j, k, tmp_in;

    while (~scanf("%d", &input)) {
        first = 0, time = 0;
        tmp_in = sqrt(MAX_LEN);
        for (i = 2; i <= tmp_in; i++) {
            if (input%i==0) {
                input/=i;
                time++;
                i--;
            }
            else if (i==tmp_in && input>tmp_in) {
                if (first!=0) {
                    putchar('*');
                }
                printf("%d^1", input);
            }
            else {
                if (time!=0) {
                    if (first!=0) {
                        putchar('*');
                    }
                    else {
                        first=1;
                    }
                    printf("%d^%d", i, time);
                    time = 0;
                }
                else {
                    continue;
                }
            }
        }
        putchar('\n');
    }
    return 0;
}
