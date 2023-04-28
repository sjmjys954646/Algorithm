#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char a;
	int i = 0;
	int num = 1;
	char arr[1000001];

	gets(arr);

	while (arr[i] != NULL)
	{
		if ((int)arr[i] == 32 && arr[i + 1] != NULL)
		{
			num++;
		}
		i++;
	}

	if (arr[0] = NULL || (int)arr[0] == 32)
	{
		num--;
	}

	printf("%d", num);


	return 0;
}
