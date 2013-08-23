#include <cstdio>
#include <cstdlib>
#include <cmath>

#define MAX_LEN 1000000

int prime[50000];
bool e_prime[MAX_LEN];

int main(int argc, char *argv[])
{
    int first, time, input, i, j, k;

    int sqrt_num = sqrt(MAX_LEN);
    e_prime[0] = e_prime[1] = 1;
    for (i = 2; i <= sqrt_num; i++) {
        if (!e_prime[i]) {
            for (j = (MAX_LEN-1)/i, k = i*j; j>=i ; j--, k-=i) {
                if (!e_prime[j]) {
                    e_prime[k] = 1;
                }
            }
        }
    }

    int prime_num = 0;
    for (i = 0; i < MAX_LEN; i++) {
        if (!e_prime[i]) {
            prime[prime_num++] = i;
            //printf("%d\n", i);
        }
    }

    while (~scanf("%d", &input)) {
        first = 0, time = 0;
        for (i = 0; i < prime_num; i++) {
            if (input%prime[i]==0) {
                input/=prime[i];
                time++;
                i--;
            }
            else if (i==prime_num-1) {
                if (input!=1) {
                    if (first!=0) {
                        putchar('*');
                    }
                    else {
                        first=1;
                    }
                    printf("%d", input);
                }
            }
            else {
                if (time!=0) {
                    if (first!=0) {
                        putchar('*');
                    }
                    else {
                        first=1;
                    }
                    printf("%d^%d", prime[i], time);
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
