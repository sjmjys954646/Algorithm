#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <cstring>

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
	int T;

	cin >> T;

	while (T--)
	{
		int a, b;
		cin >> a >> b;
		cout << a * b / LCM(a, b)<<"\n";
	}


	return 0;
}