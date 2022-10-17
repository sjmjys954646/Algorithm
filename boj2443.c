#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>    


int main()
{
	int num;

	scanf("%d", &num);

	for (int i = num;i > 0;i--)
	{
		for (int j = num - i+1;j > 1;j--)
		{
			printf(" ");
		}

		for (int j = 0; j < 2 *i  - 1;j++)
		{
			printf("*");
		}

		printf("\n");
	}
	
	
	return 0;
}