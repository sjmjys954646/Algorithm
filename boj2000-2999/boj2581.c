#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int arr[10002];
	int M, N;
	int total = 0;
	int min = 0;
	
	scanf("%d %d", &M, &N);
	
	for(int i =1;i<10002;i++)
		arr[i] = i;
	
	for(int i =2;i < 10002;i++)
	{
		for(int k = 2;i*k<10002;k++)
		{	
			arr[i*k] = 0;
		}	
	}
	
	arr[1] = 0;
	
	for(int i =M;i<=N;i++)
	{
		if(!arr[i])
			continue;
		
		total+=arr[i];
		
		if(!min)
			min = arr[i];
	}
	
	if(!min)
	{
		printf("-1");
	}
	else
	{
		printf("%d\n%d", total, min);
	}
	
	return 0;
} 