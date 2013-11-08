#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1000

int main()
{
    int n, A[MAX_LEN], first, i, j;
    while(scanf("%d", &n))
    {
        first = 0;
        memset(A, 0, sizeof(A));
        A[0] = 1;
        if(n==0)
            break;
        else if(n==1)
            printf("1\n");
        else if(n==2)
            printf("4\n");
        else
        {
            for (i=n+2;i<=2*n;i++)
            {
                for (j=0;j<MAX_LEN;j++)
                {
                    A[j]*=i;
                }
                for (j=0;j<MAX_LEN-1;j++)
                {
                    A[j+1]+=A[j]/10;
                    A[j]%=10;
                }
            }
            for (i=MAX_LEN-1;i>=0;i--)
            {
                if (first==0 && A[i]==0)
                {
                    continue;
                }
                else
                {
                    first=1;
                }
                printf("%d", A[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
