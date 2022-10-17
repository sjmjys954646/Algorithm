#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>  


int main()
{
	int num;
	int result;

	scanf("%d", &num);

	result = Factorial(num);

	printf("%d", result);

	return 0;
}

int Factorial(int n)
{
	if (n == 0)
	{
		return 1;
	}
	return n * Factorial(n - 1);
}