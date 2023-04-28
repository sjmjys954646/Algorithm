#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a;
	int ans = 0;

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &a);
		ans += a * a;
	}
	ans = ans % 10;

	printf("%d", ans);

	return 0;
	
}