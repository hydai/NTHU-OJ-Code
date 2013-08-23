#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int mode;

int F(int n)
{
   if (n==0) {
      return 0;
   }
   else if (n==1) {
      return 1;
   }
   else if (n%2==0) {
      return (F(n/2)*(2*F(n/2-1)+F(n/2)))%mode;
   }
   else if (n%2==1) {
      return (F((n+1)/2)*F((n+1)/2) + F((n+1)/2-1)*F((n+1)/2-1))%mode;
   }
   return 0;
}

int main(int argc, char *argv[])
{
   int n, m;

   while (~scanf("%d%d", &n, &m)) {
      mode = 1 << m;
      printf("%lld\n", F(n)%mode);
   }
   return 0;
}
