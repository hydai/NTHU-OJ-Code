#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>

#define HALF 46400
using namespace std;
bool isPrime[HALF];
int primes[HALF/2];
int primes_ct;
void initPrime();
int main(int argc, char *argv[])
{
    int L, U;
    initPrime();
    while (~scanf("%d%d", &L, &U)) {
        int maxID = -1, minID = -1;
        int maxD = 0, minD = 100000000;
        vector<int> primeV;
        for (long long i = L; i <= U; i++) {
            if ((i < HALF) && (!isPrime[i])) {
                continue;
            }
            if (i >= HALF) {
                bool isP = true;
                int root = sqrt(i);
                for (int j = 0; primes[j] <= root ; j++) {
                    if (i % primes[j] == 0) {
                        isP = false;
                        break;
                    }
                }
                if (!isP) {
                    continue;
                }
            }
            primeV.push_back(i);
        }

        for (int i = 0; i < primeV.size()-1; i++) {
            int div = primeV[i+1] - primeV[i];
            if (div > maxD) {
                maxD = div; maxID = i;
            }
            if (div < minD) {
                minD = div; minID = i;
            }
        }
        if (maxID == -1) {
            printf("There are no adjacent primes.\n");
        }
        else {
            printf("%d,%d are closest, %d,%d are most distant.\n", 
                    primeV[minID],
                    primeV[minID+1],
                    primeV[maxID],
                    primeV[maxID+1]);
        }
    }
    return 0;
}

void initPrime() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = 0;
    isPrime[1] = 0;
    for (int i = 2; i < HALF; i++) {
        if (isPrime[i]) {
            primes[primes_ct++] = i;
            for (int j = i*2; j < HALF; j+=i) {
                isPrime[j] = 0;
            }
        }
    }
}
