#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>  


int main()
{
	int arr[8];
	int num = 0;

	for (int i = 0;i < 8;i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 7;i > 0;i--)
	{
		if (arr[i] - 1 == arr[i - 1] )
		{
			num++;
		}
		else if (arr[i] + 1 == arr[i - 1])
		{
			num--;
		}		
	}

	if (num == 7)
	{
		printf("ascending");
	}
	else if (num == -7)
	{
		printf("descending");
	}
	else
	{
		printf("mixed");
	}

	return 0;
}