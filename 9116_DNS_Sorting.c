#include <stdio.h>
#include <string.h>

#define MAX_LEN 10000000+10

char bufferStr[MAX_LEN];

int main(int argc, char *argv[])
{
    while (~scanf("%s", bufferStr)) {
        int i, V[4] = {};
        long long int ans = 0;
        int len = strlen(bufferStr);
        for (i = len-1; i >= 0; i--) {
            switch(bufferStr[i]) {
                case 'A':
                    V[0]++;
                    break;
                case 'C':
                    V[1]++;
                    ans += V[0];
                    break;
                case 'G':
                    V[2]++;
                    ans += V[0] + V[1];
                    break;
                case 'T':
                    V[3]++;
                    ans += V[0] + V[1] + V[2];
                    break;
                default:
                    break;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
