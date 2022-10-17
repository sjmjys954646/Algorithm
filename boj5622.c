#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char arr[16];
	int total = 0;
	
	scanf("%s", arr);
	
	for(int i =0;i<strlen(arr);i++)
	{		
		if(arr[i] == 'A' || arr[i] == 'B' || arr[i] == 'C')
		{
			total+=3;
		}
		else if(arr[i] == 'D' || arr[i] == 'E' || arr[i] == 'F')
		{
			total+=4;
		}
		else if(arr[i] == 'G' || arr[i] == 'H' || arr[i] == 'I')
		{
			total+=5;
		}
		else if(arr[i] == 'J' || arr[i] == 'K' || arr[i] == 'L')
		{
			total+=6;
		}
		else if(arr[i] == 'M' || arr[i] == 'N' || arr[i] == 'O')
		{
			total+=7;
		}
		else if(arr[i] == 'P' || arr[i] == 'Q' || arr[i] == 'R' || arr[i] == 'S')
		{
			total+=8;
		}
		else if(arr[i] == 'T' || arr[i] == 'U' || arr[i] == 'V')
		{
			total+=9;
		}
		else
		{
			total+=10;
		}
	}
	
	
	
	printf("%d", total);
	
	
	return 0;
}