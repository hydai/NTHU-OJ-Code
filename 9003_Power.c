#include <stdio.h>

#define LEN 1000

void set( short ans[], int input )
{
	int i;
	for(i=0;i<LEN;i++)
		ans[i] = 0;
	ans[0] = input % 10;
	ans[1] = input /10 % 10;
	ans[2] = input /100;
}

int calc_length( short n[] )
{
	int length = 0;
	int check_flag = 0;
	int i;
	for( i=LEN-1 ; i>=0 ; i-- )
	{
		if( (n[i] == 0) && (check_flag == 0) )
			continue;
		else
			check_flag = 1;
        
		length++;
	}
	return length;
}

void run( short ans[], int a, int b )
{
	int i, j;
	int carry = 0, temp;
    
	for( i=2 ; i<=b ; i++ )
		for( j=0 ; j<LEN ; j++ )
		{
			temp = ans[j]*a + carry;
			ans[j] = temp % 10;
			carry = temp / 10;
		}
}

void print_result( short ans[] )
{
	int i, length;
	length = calc_length(&*ans);
    
	for( i=length-1 ; i>=0 ; i-- )
		printf("%d", ans[i]);
    
	printf("\n");
}

int main()
{
	short ans[LEN] = {0}, next[LEN] = {0};
    int times, a, b;
	scanf("%d", &times);
    
	while ( times != 0 )
	{
		scanf("%d%d", &a,&b);
		set(ans, a);
		run(ans, a, b);
		print_result(ans);
		times--;
	}
	return 0;
}
