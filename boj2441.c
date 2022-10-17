#include <stdio.h>


int main(void)
{
	int N;
	int i;
	int j;
	int k;
	scanf("%d", &N);

	for (i = 1;i <= N;i++)
	{
		for (j=1;j <= i-1;j++)
		{
			printf(" ");
		}
		for (k=1;k <= N-i+1;k++)
		{
			printf("*");
		}		
		printf("\n");
	}


	return 0;
}