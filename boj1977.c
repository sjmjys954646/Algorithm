#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int A, B;
	float ansA;
	int ansB;
	int total = 0;
	int ans;

	scanf("%d %d", &A, &B);
	ansA = sqrt((float)A);
	ansB = sqrt((float)B);
	
	ansA = ceil(ansA);
	
	if (ansA >= ansB)
	{
		printf("-1");
	}
	else
	{
		ans = ansA * ansA;
		for (int i = ansA; i <= ansB; i++)
		{
			total += i * i;
		}
		printf("%d\n%d", total, ans);
	}
	

	return 0;
}