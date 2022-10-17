#include <stdio.h>

int main(void)
{
	char A[100];
	int i = 0;
	gets(A);

	while (1)
	{
		printf("%c", A[i]);
		i++;
		if (A[i] == 0)
		{
			break;
		}
		if (i % 10 == 0)
		{
			printf("\n");
		}
	}

	return 0;
}