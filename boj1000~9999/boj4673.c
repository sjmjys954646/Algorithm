#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>    

int FindSelf(int i);

int main()
{
	int arr[10000];
	int num;


	for (int i = 1;i < 10001;i++)
	{
		arr[i-1] = i;
	}

	for (int i = 1;i < 10001;i++)
	{
		num = FindSelf(i);
		if (num < 10000)
		{
			arr[num-1] = 0;
		}
	}

	for (int i = 0;i < 9999;i++)
	{
		if (arr[i] != 0)
		{
			printf("%d\n", arr[i]);
		}
	}
}

int FindSelf(int i)
{
	int total = 0;
	total += i;

	while (i != 0)
	{
		total += i % 10;
		i /= 10;
	}
	return total;
}
