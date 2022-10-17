#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int A, B;
	int arr[1000]; 
	int count = 1;
	int total = 0;
	int ans = 0;

	scanf("%d %d", &A, &B);

	for (int i = 0; i < 1000; )
	{
		total += count;
		for (; i < total && i < 1000; i++)
		{
			arr[i] = count;			
		}
		count++;
	}

	for (int j = A-1; j <= B-1; j++)
	{
		ans += arr[j];
	}
	
	printf("%d", ans);

	return 0;
}