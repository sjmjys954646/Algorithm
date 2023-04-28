#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int X;

	scanf("%d", &X);
	
	int binary[20] = { 0, };
	int count = 0;
	int position = 0;

	while (1)
	{
		binary[position] = X % 2;
		X = X / 2;

		position++;
		 
		if ( X == 0)    // ¸òÀÌ 0ÀÌ µÇ¸é ¹Ýº¹À» ³¡³¿
			break;
	}

	for (int i = position - 1; i >= 0; i--)
	{
		if (binary[i] == 1)
		{
			count += 1;
		}
	}

	printf("%d", count);
}