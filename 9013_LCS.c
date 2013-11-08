#include <stdio.h>
#include <string.h>

int mmax (int a, int b) {
    return (a>b)?a:b;
}

int max (int a, int b, int c, int d) {
    int m = a;
    m = (m>b)?m:b;
    m = (m>c)?m:c;
    m = (m>d)?m:d;
    return m;
}

int main(int argc, char *argv[])
{
    char s1[1000], s2[1000];
    int LCS[1050][1050];
    int t, len1, len2;
    int i, j;
    int k, l;
    scanf("%d", &t);
    while (t--) {
        scanf("%s%s", s1, s2);
        len1 = strlen(s1);
        len2 = strlen(s2);
        memset(LCS, 0, sizeof(LCS));
        for (i = 1; i <= len1; i++) {
            for (j = 1; j <= len2; j++) {
                printf("----------STATE----------\n");
                for (k = 0; k <= len1; k++) {
                    for (l = 0; l <= len2; l++) {
                        printf("%d ", LCS[k][l]);
                    }
                    putchar(10);
                }
                printf("----------END------------\n");
                if (s1[i-1] == s2[j-1]) {
                    LCS[i][j] = mmax(LCS[i][j], LCS[i-1][j-1]+1);
                }
                else {
                    LCS[i][j] = max(LCS[i][j], LCS[i-1][j], LCS[i-1][j-1], LCS[i][j-1]);
                }
            }
        }
        printf("%d\n", LCS[len1][len2]);
    }
    return 0;
}
