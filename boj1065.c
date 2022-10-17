#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>    

int FindHan(int i);

int main()
{
	int arr[1001] = { 0, };
	int ans = 0;
	int N;

	scanf("%d", &N);

	for (int i = 1;i < 100;i++)
	{
		arr[i] = 1;
	}

	for (int i = 100;i < 1000;i++)
	{
		arr[i] = FindHan(i);
	}

	for (int i = 1;i <= N;i++)
	{
		if (arr[i] == 1)
		{
			ans += 1;
		}
	}

	printf("%d", ans);
}

int FindHan(int num)
{
	int numarr[3];

	for (int i = 0;i < 3;i++)
	{
		numarr[i] = num % 10;
		num = num / 10;
	}

	if (numarr[2] - numarr[1] == numarr[1] - numarr[0])
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

