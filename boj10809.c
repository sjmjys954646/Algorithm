#include<stdio.h>
#include<math.h>
#include<string.h>


int main()
{
	char string[100];
	int arr[26];
	
	for(int i = 0 ;i<26;i++)
	{
		arr[i] = -1;
	}
	
	scanf("%s", string);
	
	for(int i = 0 ;i<strlen(string);i++)
	{
		if(arr[(int)string[i] - 97] == -1)
			arr[(int)string[i] - 97] = i;
	}
	
	for(int i =0;i<26;i++)
	{
		if(i == 25)
		{	
			 printf("%d",arr[i]);
		}
		else
		{
			 printf("%d ",arr[i]);
		}
	}
	return 0;
}