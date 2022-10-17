#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stdio.h>
#include <string>
#include <math.h>
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

int LCM(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int a, b;
	int tmp;

	cin >> a >> b;

	tmp = Min(a, b);
	b = Max(a, b);
	a = tmp;

	cout << LCM(a, b) << "\n" << a*b/LCM(a,b);


	return 0;
}