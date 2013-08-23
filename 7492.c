#include <stdio.h>

int main(int argc, char *argv[])
{
	long long int a, b, tmp_a, tmp_b, gcd, tmp;
	while (EOF!=scanf("%lld%lld", &a, &b))
	{
		gcd = 0;
		tmp_a = a;
		tmp_b = b;
	
		while (b>0)
		{
			if (a>b)
			{
				tmp = a;
				a = b;
				b = tmp;
			}
		
			b %= a;
		}
		gcd = a;
		
		printf("%lld\n", (tmp_a*tmp_b)/gcd);
	}
	return 0;
}