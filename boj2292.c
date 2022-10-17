#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>  

int main(void) 
{
	int n;

	scanf("%d", &n);
	
	for (int i = 0;;i++)
	{
		if (n == 1)
		{
			printf("%d", 1);
			break;
		}

		if (n > 3 * i*(i + 1) + 1 && n <= 3 * (i + 1)*(i + 2) + 1)
		{
			printf("%d", i + 2);
			break;
		}
	}

	return 0;
}