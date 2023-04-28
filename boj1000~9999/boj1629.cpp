#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stdio.h>
#include <string>
#include<string.h>
#include <math.h>
#include <map>
#include <stack>
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

int ans = 1;

long long int power(long long int a, long long int b, long long int c) 
{
	if (b == 0)
		return 1;

	long long int tmp;

	if (b % 2 == 0) 
	{
		tmp = power(a, b / 2, c);
		return tmp * tmp % c;
	}

	else 
	{
		tmp = power(a, (b - 1) / 2, c);
		return ((a % c* tmp%c) * tmp %c) % c;
	}
}

int main() 
{
	long long int A, B, C;

	cin >> A >> B >> C;

	cout << power(A, B, C);

	return 0;
}

