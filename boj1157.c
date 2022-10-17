#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	int arr[26] = {0,};
	char c[1000001];
	int k;
	int max = 0;
	int index;
	int len;
	
	scanf("%s", c);
	
	for(int i =0;;i++)
	{
		if(c[i] == '\0')
			break;
		
		k = c[i];
		if(k < 97)
		{
			arr[k-65]++;
		}
		else
		{
			arr[k-97]++;
		}
	}
	
	for(int i =0;i<26;i++)
	{
		if(max<arr[i])
		{
			max = arr[i];
			index = i;
		}
			
	}
	
	for(int i =0;i<26;i++)
	{
		if(max == arr[i] && i!=index)
		{
			max = -1;
			break;
		}	
	}
	
		
	if(max == -1)
	{
		printf("?");
	}
	else
	{
		printf("%c",index+65);
	}
	return 0;
}