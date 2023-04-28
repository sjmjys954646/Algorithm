#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char arr[100];
	int i = 0;

	gets(arr);

	for (; i < 100; i++)
	{
		if (arr[i] == NULL)
		{
			break;
		}
	}

	printf("%d", i);

	return 0;
}