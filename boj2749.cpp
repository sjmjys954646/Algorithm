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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	const int p = 1500000;

	int fibo[p] = { 0,1 };

	long long n;

	cin >> n;

	for (int i = 2; i < p; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		fibo[i] %= 1000000;
	}

	cout << fibo[n % p] << "\n";
	

	return 0;
}
