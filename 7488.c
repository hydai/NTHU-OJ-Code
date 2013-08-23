#include <stdio.h>

int main(int argc, char *argv[])
{
	int n;
	long long int a, b, c, tmp;
	scanf("%d", &n);
	while (n>0)
	{
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a>b)
		{
			tmp = a;
			a = b;
			b = tmp;
		}
		if (b>c)
		{
			tmp = b;
			b = c;
			c = tmp;
		}
		if (a>b)
		{
			tmp = a;
			a = b;
			b = tmp;
		}
		
		if (a<=0 || b<=0 || c<=0)
			printf("Oh~NO!!\n");
		else if (a+b <= c)
			printf("Oh~NO!!\n");
		else if (a==b && b==c)
			printf("3 equal\n");
		else if (a==b || b==c || c==a)
			printf("2 equal\n");
		else
			printf("OK!\n");
		n--;
	}

	return 0;
}