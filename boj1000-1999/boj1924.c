#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x, y;
	int ans = 0;

	scanf("%d %d", &x, &y);

	if (x != 1)
	{
		for (int i = 2;i <= x;i++)
		{
			if (i == 3)
			{
				ans += 28;
			}
			else if (i == 5 || i == 7 || i == 10 || i == 12)
			{
				ans += 30;
			}
			else
			{
				ans += 31;
			}
		}
	}
	
	ans += y;
	ans %= 7;
	if (ans == 1)
	{
		printf("MON");
	}
	else if (ans == 2)
	{
		printf("TUE");
	}
	else if (ans == 3)
	{
		printf("WED");
	}
	else if (ans == 4)
	{
		printf("THU");
	}
	else if (ans == 5)
	{
		printf("FRI");
	}
	else if (ans == 6)
	{
		printf("SAT");
	}
	else
	{
		printf("SUN");
	}

	return 0;
}