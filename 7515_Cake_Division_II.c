#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 155

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
    long long int b[MAX_LEN], p[MAX_LEN], q, ans;
    int n, i;
    
    while (~scanf("%d%lld", &n, &m))
    {
        ans = 0;
        for (i = 0; i < n; i++) {
            scanf("%lld", &b[i]);
        }
        for (i = 0; i < n; i++) {
            scanf("%lld", &p[i]);
        }
        
        for (i = 0; i < n; i++) {
            b[i] %= m;
            ans += mode(b[i], p[i]);
            ans %= m;
        }
        printf("%lld piece(s) of cake left.\n", ans);
    }
    return 0;
}
