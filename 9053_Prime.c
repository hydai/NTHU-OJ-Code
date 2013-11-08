#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000+1

int Primes[MAX], numOfPrimes;
void findPrimes() {
    int List[MAX] = {0}, i, j;
    numOfPrimes = 0;
    for (i = 2; i <= MAX; i++) {
        if (!List[i]) {
            Primes[numOfPrimes++] = i;
        }
        for (j = 0; Primes[j] <= i && Primes[j]*i <= MAX; j++) {
            List[Primes[j]*i] = 1;
            if (i % Primes[j] == 0) {
                break;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int PrefixSum[MAX] = {0};
    int i, indexOfPrimes = 0;
    int t, a, b;
    findPrimes();

    PrefixSum[0] = 0;
    for (i = 1; i < MAX; i++) {
        PrefixSum[i] = PrefixSum[i-1];
        if (i == Primes[indexOfPrimes]) {
            PrefixSum[i]++;
            indexOfPrimes++;
        }
    }

    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", PrefixSum[b]-PrefixSum[a-1]);
    }
    return 0;
}
