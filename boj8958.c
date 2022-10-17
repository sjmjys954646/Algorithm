#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>  

int main()
{
	int num;
	char arr[80] = {0, };
	int total = 0;
	int score = 0;
	int length = 0;

	scanf("%d\n", &num);

	for (int i = 0;i < num;i++)
	{
		total = 0;
		gets(arr);

		for (int j = 0;arr[j] != 0;j++)
		{	
			if (arr[j] == 'O')
			{
				if (j == 0)
				{
					score = 1;
					total += score;
					continue;
				}

				if (arr[j - 1] == 'O')
				{
					score++;
					total += score;
				}
				else if(arr[j - 1] == 'X')
				{
					score = 1;
					total += score;
				}
			}
			else if (arr[j] == 'X')
			{
				score = 0;
			}
			
		}
		printf("%d\n", total);
	}
	
	return 0;
}