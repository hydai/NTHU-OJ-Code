#include <stdio.h>
#define MAX 1000

int arr[MAX];

int main()
{
	int a, b, swap_tmp, tmp_up, tmp_down, i, j;
	while(~scanf("%d%d", &a, &b))
	{
		i = 0;
		tmp_up = a, tmp_down = b;

		while(1)
		{
			arr[i] = tmp_up/tmp_down;
			tmp_up%=tmp_down;
			if (tmp_up==1) {
			    arr[i+1] = tmp_down;
			    i++;
			    break;
			}
			swap_tmp = tmp_up, tmp_up  = tmp_down, tmp_down = swap_tmp;
			i++;
		}
		putchar('[');
		printf("%d", arr[0]);
		putchar(';');
		for(j = 1; j < i; j++)
		{
			printf("%d", arr[j]);
			putchar(',');
		}
		printf("%d", arr[j]);
		putchar(']');
		putchar('\n');
	}
	return 0;
}
