#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int T;
	int K, N;
	
	int arr[15][15] = {0,};
	
	for(int i =0;i<15;i++)
	{
		arr[0][i] = i;	
	}
	
	for(int i =1;i<15;i++)
	{
		for(int j = 0;j<15;j++)
		{
			for(int z = 0;z<=j;z++)
			{
				arr[i][j] += arr[i-1][z];
			}
		}
	}
	
	scanf("%d", &T);
	
	for(int i = 0;i<T;i++)
	{
		scanf("%d", &K);
		scanf("%d", &N);
		
		printf("%d\n", arr[K][N]);
	}
	return 0;
} 