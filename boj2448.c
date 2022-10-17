#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>    
#include <math.h>

void Pibo(int num, int a, int b, char arr[3072][6144]);

char arr[3072][6144];

int main()
{
	int num;
	int a, b;
	int c, d;
	int k = 0;
	int l;


	scanf("%d", &num);
	l = num;
	num = num / 3;
	if (num > 2)
	{
		for (;num > 2;k++)
		{
			num /= 2;		
		}
		num = k + 2;
	}
	
	a = l - 1;
	b = 0;
		
	c = l;
	d = 2*l -1;
	
	for (int i = 0;i < c;i++)
	{
		for (int j = 0;j < d;j++)
		{		
			arr[i][j] = ' ';							
		}
	}

	Pibo(num, a, b, arr);

	for (int i = 0;i < c ;i++)
	{
		for (int j = 0;j <d;j++)
		{
			printf("%c",arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}

void Pibo(int num,int a, int b, char arr[3072][6144])
{
	
	if (num == 1)
	{		
		arr[b + 2][a + 2] = '*';
		arr[b + 2][a + 1] = '*';
		arr[b + 2][a ]  = '*';
		arr[b + 2][a - 1] = '*';
		arr[b + 2][a - 2] = '*';
		arr[b + 1][a + 1] = '*';
		arr[b + 1][a - 1] = '*';
		arr[b][a] = '*';
		return;
	}
	else
	{
		Pibo(num - 1, a, b, arr);
		Pibo(num - 1, a + 3 * ((int)pow(2, num -2) ), b + 3 * ((int)pow(2, num - 2)), arr);
		Pibo(num - 1, a - 3 * ((int)pow(2, num - 2)), b + 3 * ((int)pow(2, num - 2)), arr);
	}
}