#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10000+1

int primes[MAX];
int numOfPrimes;

void findPrimes() {
    int List[MAX] = {0}, i, j;
    numOfPrimes = 0;
    for (i = 2; i < MAX; ++i) {
        if (!List[i]) {
            primes[numOfPrimes++] = i;
        }
        for (j = 0; primes[j] <= i && primes[j]*i <= MAX; j++) {
            List[primes[j]*i] = 1;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int i, j, M, N, Mi, Ni, MM;
    findPrimes();
    while (~scanf("%d%d", &M, &N)) {
        int M_List[1250] = {0}, N_List[1250] = {0};
        int space = 0;
        if (M == N || N == 0) {
            printf("1\n");
            continue;
        }
        MM = 0;
        for (i = M; i > M-N; i--) {
            j = i;
            Mi = 0;
            while (j && Mi < numOfPrimes) {
                while (j%primes[Mi] == 0) {
                    j/=primes[Mi];
                    M_List[Mi]++;
                }
                Mi++;
            }
            MM = (MM > Mi)?MM:Mi;
        }
        for (i = 1; i <= N; i++) {
            j = i;
            Ni = 0;
            while (j && Ni < numOfPrimes) {
                while (j%primes[Ni] == 0) {
                    j/=primes[Ni];
                    N_List[Ni]++;
                }
                Ni++;
            }
        }
        for (i = 0; i < MM; i++) {
            M_List[i] -= N_List[i];
        }
        for (i = 0; i < MM; i++) {
            if (M_List[i] >= 1 && space++) {
                putchar('*');
            }
            if (M_List[i] >= 2) {
                printf("%d^%d", primes[i], M_List[i]);
            }
            else if(M_List[i] == 1){
                printf("%d", primes[i]);
            }
        }
        putchar(10);
    }
    return 0;
}
