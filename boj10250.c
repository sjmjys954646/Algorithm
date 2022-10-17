#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int arr[1000];
	int T;
	int H, W, N;
	
	scanf("%d", &T);
	
	for(int i =0;i<T;i++)
	{
		scanf("%d %d %d", &H, &W, &N);
		
		if(N%H == 0)
		{
			printf("%d\n", H*100 + N/H);
		}
		else
		{
			printf("%d\n", N%H*100 + N/H +1);
		}
	}
	
	return 0;
} 