#include <stdio.h>


int main(void)
{
	double A;
	double B;

	scanf("%lf %lf", &A, &B);
	printf("%.10lf", A/B);
	
	return 0;
}