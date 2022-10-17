#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>  

int Fibo(int n);

int main()
{
	int num;

	scanf("%d", &num);

	printf("%d", Fibo(num+1));
		
	return 0;
}

int Fibo(int n)
{
	int arr[2] = { 0,1 };
	int temp = 0;

	if (n == 1)
	{
		return arr[0];
	}
	else if (n == 2)
	{
		return arr[1];
	}

	for (int i = 0; i < n-2; i++)
	{
		temp = arr[0] + arr[1];
		arr[0] = arr[1];
		arr[1] = temp;
	}
	return temp;
}