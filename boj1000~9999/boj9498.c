#include <stdio.h>

int main(void)
{
	int a;
	scanf("%d", &a);

	if (a <= 100 && 90 <= a)
	{
		printf("A");
	}
	else if (a <= 89 && 80 <= a)
	{
		printf("B");
	}
	else if (a <= 79 && 70 <= a)
	{
		printf("C");
	}
	else if (a <= 69 && 60 <= a)
	{
		printf("D");
	}
	else
	{
		printf("F");
	}
	return 0;
}
