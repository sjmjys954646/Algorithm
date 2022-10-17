#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a;
	int ans = 0;

	for (int j = 0; j < 3; j++)
	{
		ans = 0;
		for (int i = 0; i < 4; i++)
		{
			scanf("%d", &a);
			ans += a;
		}

		if (ans == 1)
		{
			printf("C");
		}
		else if (ans == 2)
		{
			printf("B");
		}
		else if (ans == 3)
		{
			printf("A");
		}
		else if (ans == 4)
		{
			printf("E");
		}
		else if (ans == 0)
		{
			printf("D");
		}
		printf("\n");
	}
	
	return 0;
	
}