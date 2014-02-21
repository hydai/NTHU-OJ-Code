#include <stdio.h>
#include <string.h>

#define len 102

struct Big_number
{
	short sign;
	int length;
	char in_num[len];
	int per_num[len];
};


void input_number( struct Big_number *num )
{
	scanf("%s", num -> in_num);
	num -> length = strlen( num -> in_num );

	int i;
	for( i = num -> length - 1 ; i >= 0 ; i-- )
	{
		if( num -> in_num[0] == '-' )
		{
			num -> sign = 1;
			num -> length--;
			break;
		}
		num -> per_num[num -> length - i + 1] = num -> in_num[i] - '0';
	}
}

int who_is_bigger( struct Big_number *num1, struct Big_number *num2)
{
	if( num1 -> length > num2 -> length )
		return 0;
	else if( num1 -> length < num2 -> length )
		return 1;

	int i;
	for( i = num1 -> length ; i >= 0 ; i-- )
		if( num1 -> per_num[i] == num2 -> per_num[i] )
			continue;
		else if( num1 -> per_num[i] > num2 -> per_num[i] )
			return 0;
		else
			return 1;
}

void add_number( struct Big_number *num1, struct Big_number *num2, struct Big_number *ans )
{
	ans -> length = ( num1 -> length > num2 -> length ) ? num1 -> length : num2 -> length;

	int i;
	if( num1 -> sign == num2 -> sign ) //same sign
	{
		//signed
		ans -> sign = num1 -> sign;
		//add
		for( i = 0 ; i < ans -> length ; i++ )
			ans -> per_num[i] = num1 -> per_num[i] + num2 -> per_num[i];
		//carry
		for( i = 0 ; i < ans -> length ; i++)
			if( ans -> per_num[i] > 10 )
			{
				ans -> per_num[i] %= 10;
				ans -> per_num[i+1] ++;
			}
	}
	else							   //diff sign
	{
		int state;
		/*
		state = 0 -> num1 >= num2
		state = 1 -> num1 <  num2
		*/
		state = who_is_bigger( &*num1, &*num2 );
		
		if( state == 0 )
		{
			//calc
			for( i = 0 ; i < num1 -> length ; i++ )
				ans -> per_num[i] = num1 -> per_num[i] - num2 -> per_num[i];
			//carry
			for( i = 0 ; i < num1 -> length ; i++ )
				if( ans -> per_num[i] < 0 )
				{
					ans -> per_num[i] += 10;
					ans -> per_num[i+1] --;
				}

			if( num1 -> sign == 0 )
				ans -> sign = 0;
			else
				ans -> sign = 1;
		}
		else
		{
			//calc
			for( i = 0 ; i < num2 -> length ; i++ )
				ans -> per_num[i] = num2 -> per_num[i] - num1 -> per_num[i];
			//carry
			for( i = 0 ; i < num2 -> length ; i++ )
				if( ans -> per_num[i] < 0 )
				{
					ans -> per_num[i] += 10;
					ans -> per_num[i+1] --;
				}

			if( num2 -> sign == 0 )
				ans -> sign = 0;
			else
				ans -> sign = 1;
		}
	}

}

void print_ans( struct Big_number *ans )
{
	int i, counter;

	if( ans -> sign == 1 )
		printf("-");

	counter = ans -> length;
	while( ans -> per_num[ counter ] == 0 )
		counter--;
	for( i = counter ; i >= 0 ; i-- )
		printf("%d", ans -> per_num[i]);

	printf("\n");
}

int main()
{
	struct Big_number big_num1, big_num2, answer_num;

	//reset

	int i;
	for( i = 0 ; i < len ; i++ )
	{
		big_num1.per_num[i] = 0;
		big_num2.per_num[i] = 0;
		answer_num.per_num[i] = 0;
	}

	input_number( &big_num1 );
	input_number( &big_num2 );
	add_number( &big_num1, &big_num2, &answer_num);
	print_ans( &answer_num );


	return 0;
}
