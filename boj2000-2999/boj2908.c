#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Swap(char *num1, char *num2)
{
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int main()
{
	int num1,Snum1;
	int num2,Snum2;
	char Anum1[4];
	char Anum2[4];
	int k=0;
	
	scanf("%d %d",&num1 ,&num2);
	
	sprintf(Anum1, "%d", num1);
	sprintf(Anum2, "%d" ,num2);
	
	Swap(&Anum1[0],&Anum1[2]);
	Swap(&Anum2[0],&Anum2[2]);
	
	if(atoi(Anum1)>atoi(Anum2))
	{
		printf("%d",atoi(Anum1));
	}
	else
	{
		printf("%d",atoi(Anum2));
	}
	
	return 0;
}