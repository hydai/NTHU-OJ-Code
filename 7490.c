#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[1000];

int main(int argc, char *argv[])
{
	char *pt, *next, tmp[501];
	int wnum, flag;
	while (fgets(input, sizeof(input), stdin))
	{
		wnum = 0;
		flag = 0;
		
		input[strlen(input)-1] = ' ';
		input[strlen(input)] = '\0';
		for (pt = input; *pt != '\0'; pt++)
		{
			if (!(*pt <='Z' && *pt >= 'A' || *pt <= 'z' && *pt >= 'a'))
				*pt = ' ';
		}
		pt = strstr(input," ");
		do {
			if (flag == 0 && *(pt-1) <='Z' && *(pt-1) >= 'A')
			{
				wnum ++;
			}
			pt = strstr(pt+1, " ");
			if (pt == NULL)
				break;
		}while(1);
		printf("%d\n", wnum);
	}

	return 0;
}