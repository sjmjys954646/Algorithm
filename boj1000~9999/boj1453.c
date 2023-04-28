#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int arr[100] = {0, };
	int N;
	int a;
	int count = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a);
		if (arr[a-1] == 0)		
			arr[a-1] = 1;		
		else
			count += 1;
	}
	printf("%d", count);

	return 0;
}