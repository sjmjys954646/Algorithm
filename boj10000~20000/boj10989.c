#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	int T;
	int arr[10000] = {0,};
	int k;
	
	scanf("%d",&T);
	
	for(int i =0;i<T;i++)
	{
		scanf("%d",&k);
		arr[k-1]++;
	}
	
	for(int i =0;i<10000;i++)
	{
		while(arr[i]!=0)
		{
			printf("%d\n",i+1);
			arr[i]--;
		}
	}
	return 0;
}