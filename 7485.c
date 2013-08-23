#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[1000];

int main(int argc, char *argv[])
{
	char *pt, *next;
	int wnum, flag;
	while (fgets(input, sizeof(input), stdin))
	{
		wnum = 0;
		flag = 0;
		
		input[strlen(input)-1] = '\0';
		for (pt = input; *pt != '\0'; pt++)
		{
			if (!(*pt <='Z' && *pt >= 'A' || *pt <= 'z' && *pt >= 'a'))
				*pt = ' ';
		}
		pt = input;
		do {
			if (flag == 0 && *pt <='Z' && *pt >= 'A')
			{
				flag = 1; /*head is upper*/
				wnum ++;
			}
			else
			{
				flag = 2; /*head is not upper*/
			}
			if (*pt == ' ')
				flag = 0;
				
			pt++;
		}while(*pt != '\0');
		printf("%d\n", wnum);
	}

	return 0;
}