#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	int arr[26] = {0,};
	int T;
	char word[101];
	int k=0;
	
	scanf("%d", &T);
	
	for(int i =0;i<T;i++)
	{
		scanf("%s", word);
		
		for(int j =0;j<strlen(word);j++)
		{
			if(j!=0)
			{
				if(word[j] == word[j-1])
				{							
					continue;
				}
			}
			
			if(arr[word[j]-'a']==0)
			{
				arr[word[j]-'a']++;
			}
			else
			{
				k++;					
				break;
			}
		}
		
		for(int j=0;j<26;j++)
			arr[j] = 0;
	}
	printf("%d", T-k);
	
	return 0;
}