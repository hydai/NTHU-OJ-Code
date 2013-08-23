#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct AAA {
    long long int a, b, c, d;
} ANS;

long long int mode, mod[21] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576};

void F(int n)
{
    long long int a = ANS.a%mode, b = ANS.b%mode, c = ANS.c%mode, d = ANS.d%mode;
    if (n==1) {
        ANS.a = (a + b);
        ANS.b = a;
        ANS.c = (c + d);
        ANS.d = c;
    }
    else if (n==2) {
        ANS.a = (2 * a + b)%mode;
        ANS.b = (a + b)%mode;
        ANS.c = (2 * c + d)%mode;
        ANS.d = (c + d)%mode;
    }
    else if (n%2==0) {
        F(n/2);
        /*
        F(n/2);
        */
        a = ANS.a%mode, b = ANS.b%mode, c = ANS.c%mode, d = ANS.d%mode;
        ANS.a = (a*a+b*c)%mode;
        ANS.b = (a*b+b*d)%mode;
        ANS.c = (a*c+c*d)%mode;
        ANS.d = (b*c+d*d)%mode;
    }
    else if (n%2==1) {
        F((n-1)/2);
        /*
        F((n-1)/2);
        */
        
        a = ANS.a%mode, b = ANS.b%mode, c = ANS.c%mode, d = ANS.d%mode;
        ANS.a = (a*a+b*c)%mode;
        ANS.b = (a*b+b*d)%mode;
        ANS.c = (a*c+c*d)%mode;
        ANS.d = (b*c+d*d)%mode;
        F(1);
    }
/*
printf("------------------------------------\n");
printf("ANS.a = %lld\n", ANS.a);
printf("ANS.b = %lld\n", ANS.b);
printf("ANS.c = %lld\n", ANS.c);
printf("ANS.d = %lld\n", ANS.d);
printf("------------------------------------\n");
 */
}

int main(int argc, char *argv[])
{
    int n, m;
    long long int ans;

    while (~scanf("%d%d", &n, &m)) {
        ans = 0;
        /*
        mode = 1 << m;
        */
        mode = mod[m];
        ANS.a = 1;
        ANS.b = 0;
        ANS.c = 0;
        ANS.d = 1;

        if (n==0) {
            ans = 0;
        }
        else if (n==1) {
            ans = 1;
        }
        else {
            F(n-1);
            ans = ANS.a%mode;
        }

        printf("%lld\n", ans);
    }
    return 0;
}
