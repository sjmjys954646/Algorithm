#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N;
	int cycle = 0;
	int beforechange;
	int change;
	int ten;
	int first;

	scanf("%d", &N);

	beforechange = N;
	
	for (int i = 0;; i++)
	{
		if (beforechange / 10 != 0)
		{
			ten = beforechange / 10;
			first = beforechange % 10;
			change = (ten + first) % 10 + beforechange % 10 * 10;
		}
		else
		{
			change = beforechange * 10 + beforechange;
		}

		cycle += 1;
		
		if (change == N)
		{
			break;
		}
		beforechange = change;
		change = 0;
		
	}


	printf("%d", cycle);
}