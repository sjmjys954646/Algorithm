#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>  

int main(void) 
{
	int num;
	int arr[2000] = { 0, };
	int temp;

	scanf("%d", &num);

	for (int i = 0;i < num;i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0;i < num;i++)
	{
		for (int j = 0;j < num;j++)
		{
			if (arr[j + 1] < arr[j])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}

	printf("%d", arr[num] - arr[1]);

	return 0;
}