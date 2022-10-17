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
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

int Recursive(int a)
{
	if (a == 0)
		return 0;
	else if (a == 1)
		return 1;
	else if (a == 2)
		return 1;

	return Recursive(a - 1) + Recursive(a - 2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int num;
	cin >> num;
	cout << Recursive(num);

	return 0;
}