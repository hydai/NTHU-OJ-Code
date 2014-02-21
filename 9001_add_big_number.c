#include <stdio.h>
#include <string.h>

#define LEN 1000

short sign( char n_sign )
{
	int sign = 0;
	if( n_sign == '-' )
		sign = 1;
	else
		sign = 0;
    
	return sign;
}

void get_num( char in[], short out[], short sign, int *length )
{
	int i;
	if(sign == 1)
	{
		(*length)--;
		for( i=0 ; i<*length ; i++)
		{
			out[i] = in[*length-i] - '0';
		}
	}
	else
	{
		for( i=0 ; i<*length ; i++)
			out[i] = in[*length-i-1] - '0';
	}
}

void compare_and_compute( short n1[], short n1_sign, int n1_length, short n2[], short n2_sign, int n2_length, short ans[], short *ans_sign)
{
	int temp_length;
	if(n1_length >= n2_length)
		temp_length = n1_length;
	else
		temp_length = n2_length;
	int i;
	short bigger_flag = 0;
	if( (n1_sign^n2_sign) == 0 )
	{
		*ans_sign = n1_sign;
		for(i=0 ; i < temp_length ; i++)
			ans[i] = n1[i] + n2[i];
		for(i=0 ; i < temp_length ; i++)
			if( ans[i] > 9 )
			{
				ans[i] %= 10;
				ans[i+1]++;
			}
	}
	else
	{
		for(i= temp_length ; i>=0 ; i--)
		{
			if( n1[i] > n2[i] )
			{
				*ans_sign = n1_sign;
				bigger_flag = 1;
				break;
			}
			else if( n1[i] < n2[i] )
			{
				*ans_sign = n2_sign;
				bigger_flag = 2;
				break;
			}
			else
				*ans_sign = 0;
		}
		switch(bigger_flag)
		{
			case 0:
				break;
			case 1:
				for(i=0 ; i<n1_length ; i++)
					ans[i] = n1[i] - n2[i];
				break;
			case 2:
				for(i=0 ; i<n2_length ; i++)
					ans[i] = n2[i] - n1[i];
				break;
			default:
				break;
		}
		for(i=0 ; i< temp_length ; i++)
			if( ans[i] < 0 )
			{
				ans[i] += 10;
				ans[i+1]--;
			}
	}
    
}

void print_result( short ans[], short ans_sign )
{
	short title_flag = 0;
    int check_all_zero = 0;
	int i;
	short zero_flag = 0;
    
    for(i=LEN-1 ; i>=0 ; i--)
    {
        if( ans[i] == 0 )
            check_all_zero++;
        if( (check_all_zero == LEN) && (ans) )
        {
            printf("0\n");
            zero_flag = 1;
            break;
        }
	}
    
    if( zero_flag == 1 )
        return;
    
    if( ans_sign == 1 )
		printf("-");
    
    for(i=LEN-1 ; i>=0 ; i--)
	{
		if( (ans[i] == 0) && (title_flag == 0) )
			continue;
		else
			title_flag = 1;
		printf("%d", ans[i]);
	}
	printf("\n");
}

void clear( short n1[], short n2[], short ans[] )
{
	int i;
	for(i=0;i<LEN;i++)
	{
		n1[i] = 0;
		n2[i] = 0;
		ans[i] = 0;
	}
}

int main()
{
	short n1_sign, n2_sign, ans_sign;
	short n1[LEN] = {0}, n2[LEN] = {0}, ans[LEN] = {0};
	int n1_length, n2_length;
	char n1_in[LEN], n2_in[LEN];
    
	while ( ~scanf("%s%s", n1_in, n2_in) )
	{
		n1_length = strlen(n1_in);
		n2_length = strlen(n2_in);
		n1_sign = sign(n1_in[0]);
		n2_sign = sign(n2_in[0]);
		get_num(n1_in, n1, n1_sign, &n1_length);
		get_num(n2_in, n2, n2_sign, &n2_length);
		compare_and_compute(n1, n1_sign, n1_length, n2, n2_sign, n2_length, ans, &ans_sign);
		print_result(ans, ans_sign);
        
		clear(n1,n2,ans);
	}
	return 0;
}