#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, b;
	int total = 0;
	int max = 0;

	for (int i = 0; i < 10; i++)
	{
		scanf("%d %d", &a, &b);
		total = total - a + b;
		if (total >= max)
		{
			max = total;
		}
	}

	printf("%d", max);

	return 0;
	
}