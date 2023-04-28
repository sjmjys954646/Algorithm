#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N;
	int arr[100];
	int count = 0;
	int ans=0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++)
	{	
		if (arr[i] == 1)
			continue;
		count = 0;
		for (int j = 1; j < arr[i]; j++)
		{
			if (arr[i] % j == 0)
			{
				count += 1;
			}			
		}
		if (count == 1)
		{
			ans += 1;
		}
	}

	printf("%d", ans);

	return 0;
}