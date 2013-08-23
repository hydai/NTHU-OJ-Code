#include <stdio.h>
#include <string.h>
#define max 1000000
int main()
{
	char S[max];
	int length,i;
	while( ~scanf("%s", S))
	{
		length = strlen(S);
		for(i=length-1;i>=0;i--)
			printf("%c", S[i]);
		printf("\n");
	}
	return 0;
}
