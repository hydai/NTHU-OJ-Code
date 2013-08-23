#include <stdio.h>
#include <stdlib.h>

int ans[10500];
int entry;
int main(int argc, char *argv[])
{
	int N, i, tmp, flag;
	int first = 1;
	while (EOF!=scanf("%d", &N))
	{
		entry = 0;
		for (i=0;i<N;i++)
		{
			flag = 0;
			if (i%3==0 || i%7==0)
				continue;
			else 
			{
				tmp = i;
				while(tmp > 0)
				{
					if (tmp%10 == 7 || tmp%10 == 3)
						flag = 1; /*incorrect*/
					tmp /= 10;
				}
				if (!flag)
				{
					ans[entry] = i;
					entry ++;
				}
			
			}
		}
	
		if(first != 1)
			printf("\n");
		else
			first = 0;
		
		for (i=0;i<entry-1;i++)
		{
			printf("%d ", ans[i]);
		}
		printf("%d\n", ans[entry-1]);
	}

	return 0;
}