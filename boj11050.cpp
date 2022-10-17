#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stdio.h>
#include <string>
#include <math.h>
#include <map>
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

int fac(int a)
{
	if (a == 1)
		return 1;
	return a * fac(a - 1);
}

int main()
{
	int N, K;

	cin >> N >> K;

	if (K == 0 || K == N)
	{
		cout << "1";
	}
	else
	{
		if (K > N / 2)
		{
			K = N - K;
		}

		//cout << fac(N) / (fac(N - K) * fac(K));
		cout << fac(N) / fac(N - K) / fac(K);
	}

	

	return 0;
}