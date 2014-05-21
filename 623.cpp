#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
#define MAX_LEN 3000
int NP[1000+100][MAX_LEN];

void init() {
    NP[0][0] = 1;
    NP[1][0] = 1;
    for (int i = 2; i <= 1000; i++) {
        for (int j = 0; j < MAX_LEN; j++) {
            NP[i][j] += NP[i-1][j]*i;
            NP[i][j+1] += NP[i][j]/10;
            NP[i][j] %= 10;
        }
    }
}

void printNP(int n) {
    bool isStartZero = true;
    for (int i = MAX_LEN-1; i >= 0; i--) {
        if (isStartZero && NP[n][i]==0) {
            continue;
        }
        isStartZero = false;
        printf("%d", NP[n][i]);
    }
    printf("\n");
}
int main(int argc, char *argv[])
{
    int n;
    init();
    while (~scanf("%d", &n)) {
        printf("%d!\n", n);
        printNP(n);
    }
    return 0;
}
