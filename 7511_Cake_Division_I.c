#include <stdio.h>
#include <stdlib.h>

long long int m;

long long int mode (long long int b, long long int in)
{
  long long int ans;
  b %= m;

  if (in == 0)
    ans = 1;
  else if(in == 1)
    ans = b;
  else if(in % 2==0)
  {
    ans = mode(b, in/2)%m;
    ans = (ans*ans)%m;

  }
  else if(in % 2==1)
  {
    ans = mode(b, (in-1)/2)%m;
    ans = (ans*ans*b)%m;
  }
  return ans;
}

int main()
{
  long long int b, p, q, ans;

  while (~scanf("%lld%lld%lld%lld", &b, &p, &q, &m))
  {
    p*=q;
    b %= m;
    ans = mode(b, p);
    printf("%lld piece(s) of cake left.\n", ans);
  }
  return 0;
}
