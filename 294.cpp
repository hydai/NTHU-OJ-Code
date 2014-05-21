#include <cstdio>
#include <cstring>
#define SIZE 10000
#define MAXLEN 1000000000+2
int primes[SIZE], primes_ct = 0;
bool prime[SIZE + 100];
void init();
int main(int argc, char *argv[])
{
    int t;
    scanf("%d", &t);
    init();
    while (t--) {
        int L, U;
        scanf("%d%d", &L, &U);
        int maxA = 0;
        int maxB = 0;
        int total = 1;
        for (int ii = L; ii <= U; ii++) {
            int tmp = ii, ct = 0, fac = 0;
            while (tmp != 0 && ct < primes_ct) {
                while (tmp % primes[ct] == 0) {
                    tmp /= primes[ct];
                    fac++;
                }
                if (fac != 0) {
                    total *= (fac+1);
                    fac = 0;
                }
                ct++;
            }
            if (tmp != 0) {
                total *= 2;
            }
            if (maxB < total) {
                maxB = total;
                maxA = ii;
            }
            total = 1;
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, U, maxA, maxB/2);
    }
    return 0;
}

void init() {
    memset(prime, 1, sizeof(prime));
    prime[0] = 0;
    prime[1] = 0;
    for (int i = 2; i <= SIZE; i++) {
        if (prime[i]) {
            primes[primes_ct++] = i;
            for (int j = i*i; j <= SIZE; j+=i) {
                prime[j] = 0;
            }
        }
    }
}
