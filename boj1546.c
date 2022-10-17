#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	
	int N;
	double all[1000];
	int Max = 0;
	double ans = 0;
	scanf("%d", &N);

	for (int i = 0;i < N;i++)
	{
		scanf("%lf", &all[i]);
		if (Max < all[i]) Max = all[i];
	}

	for (int i = 0;i < N;i++)
	{
		all[i] = (double)all[i] / (double)Max * 100;
	}

	for (int i = 0;i < N;i++)
	{
		ans += all[i];
	}

	ans /= N;

	printf("%lf", ans);
	return 0;
}