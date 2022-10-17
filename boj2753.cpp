#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const int INF = 987654321;

//6Àå 15¹ø
//65p.g

int IsLeapYear(int year);

int main()
{
    int num;

    scanf("%d", &num);

    printf("%d", IsLeapYear(num));
    
    return 0;
}

int IsLeapYear(int year)
{
	int n;
	if (year % 4 != 0)
		n = 0;
	else
		if (year % 100 == 0)
			if (year % 400 == 0)
				n = 1;
			else
				n = 0;
		else
			n = 1;

	return n;
}

