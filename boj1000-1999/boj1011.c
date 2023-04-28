#include<stdio.h>
#include<math.h>

int main()
{
	int T;
	double num1, num2, sub;
	int C, gap;
	
	scanf("%d",&T);
	
	for(int i =0;i<T;i++)
	{
		scanf("%lf %lf", &num1, &num2);
		sub = num2 - num1;
		C = sqrt(sub);
		gap = (int)sub - C*C;
		
		if(gap == 0)
		{
			printf("%d\n", C*2 - 1);
		}
		else if(gap <= C)
		{
			printf("%d\n", C*2);
		}
		else
		{
			printf("%d\n", C*2 +1);
		}
	}
	
	
	return 0;
}