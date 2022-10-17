#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, b;
	int arr[100];
	int ans = 0;

	scanf("%d %d", &a, &b);
	
	arr[0] = a;

	for (int i = 1; i < 100; i++)
	{
		arr[i] = arr[i-1] * a % b;
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = i+1; j < 100; j++)
		{
			if (arr[i] == arr[j])
			{
				ans = j - i;
			}
		}
	}

	printf("%d", ans);
	
	return 0;	
}