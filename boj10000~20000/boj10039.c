#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>  


int main()
{
	int num = 0;
	int total = 0;

	for (int i = 0;i < 5;i++)
	{
		scanf("%d", &num);
		if (num < 40)
			num = 40;

		total += num;
	}

	printf("%d", total / 5);
	

	
	return 0;
}