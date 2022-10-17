#include<stdio.h>
#include<math.h>
#include<string.h>


int main()
{
	int T,R;
	char Sb[20];
	char S[200] = {0,};
	int index = 0;
	
	scanf("%d", &T);
	
	for(int i =0;i<T;i++)
	{
		scanf("%d %s", &R, Sb);
		
		for(int j=0;j<strlen(Sb);j++)
		{
			for(int k =0;k<R;k++,index++)
			{
				S[index] = Sb[j];
			}
		}
		
		for(int j=0;j<strlen(S);j++)
		{
			printf("%c",S[j]);
		}
		printf("\n");
		
		memset(Sb,0,sizeof(Sb));
		memset(S,0,sizeof(S));
		index = 0;
	}
	
	return 0;
}