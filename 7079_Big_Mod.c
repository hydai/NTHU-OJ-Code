#include <stdio.h>
#include <stdlib.h>

/*value*/
int m;

/*function*/
long long int mode(int b, int p);

int main(int argc, char *argv[])
{
    int b, p;
    long long int ans;

    while (EOF != scanf("%d%d%d", &b, &p, &m)) {
        if (b%m==0) {
            ans = 0;
        }
        ans = mode(b, p);
        printf("%lld\n", ans);
    }
    return 0;
}

long long int mode(int b, int p)
{
    long long int ans = 1;

    if (p==0 || b==1) {
        return 1;
    }
    if (p==1) {
        return b;
    }

    if (p%2==0) {
        if (b>m) {
            ans = mode(b%m, p);
        }
        else if (b<m) {
            ans = mode(b*b, p/2);
        }
    }
    else {
        if (b>m) {
            ans = mode(b%m, p-1)*b;
        }
        else if (b<m) {
            ans = mode(b*b, (p-1)/2)*b;
        }

        if (ans>m) {
            ans%=m;
        }
    }

    return ans;
}
