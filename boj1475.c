#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int num, numstore;
	int arr[7];
	int ans, N, key, j;
	int len = 0;
	int subans = 1;
	int K =1;
	float T;
	
	scanf("%d", &num);
	numstore = num;
	
	while(num!=0)
	{
		num /= 10;
		len ++;
	}
	
	for(int i =0;i<len;i++)
	{
		arr[len - i -1] = numstore%10;
		numstore/=10;	
	}

	
	for(int i = 1;i<len;i++)
	{
		key = arr[i];
		for(j=i-1;j>=0 && arr[j]>key ;j--)
		{
			arr[j+1] = arr[j];		
		}		
		arr[j+1] = key;
	}
	
	for(int i =0;i<len;i++)
	{	
		j=i;
		while(arr[j]==arr[j+1] && j<len && arr[i]!=6 && arr[i]!=9 )
		{
			K+=1;
			j++;
		}
		
		if(K>subans)
		{
			subans = K;
		}
		K=1;
		i=j;
	}
	
	for(int i =0;i<len;i++)
	{
		if(arr[i]==6 || arr[i]==9)
			T+=1;	
	}
		
	T=T/2+0.5;
	
	if(T>subans)
	{
		subans = T;
	}
	
	printf("%d", subans);
	
	
	return 0;
} 