#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, b,c;
	int ans = 0;

	scanf("%d %d", &a, &b);
	scanf("%d", &c);
	ans = a * 60 + b + c;

	printf("%d %d", ans / 60 >= 24 ? ans / 60 - 24 : ans / 60 , ans % 60);
	
	return 0;	
}