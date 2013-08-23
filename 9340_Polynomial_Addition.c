#include <stdio.h>
#include <string.h>

#define MAX 1006

int main(int argc, char *argv[])
{
    int n, m, t, i, max;
    int N[MAX], M[MAX];

    scanf("%d", &t);
    while (t--) {
        memset(N, 0, sizeof(N)), memset(M, 0, sizeof(M));
        scanf("%d%d", &n, &m);
        for (i = n; i >= 0; i--)
        {
            scanf("%d", &N[i]);
        }
        for (i = m; i >= 0; i--)
        {
            scanf("%d", &M[i]);
        }
        max = (n > m)?n:m;
        for (i = max; i > 0; i--)
            printf("%d ", M[i]+N[i]);
        printf("%d\n", M[i]+N[i]);
    }
    return 0;
}
