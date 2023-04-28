#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	
	int A, N;
	int all[10000];

	scanf("%d %d", &A, &N);

	for (int i = 0;i < A;i++)
	{
		scanf("%d", &all[i]);
	}

	for (int i = 0;i < A ;i++)
	{
		if (all[i] < N)
		{
			printf("%d ", all[i]);
		}
	}

	return 0;
}
