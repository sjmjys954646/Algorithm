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


long long N, K;
long long kFact, ans, numer;

long long power(long long x, long long y)
{
	long long ret = 1;
	while (y > 0)
	{
		if (y % 2 == 1)
			ret = ret * x % 1000000007;
		x = x * x % 1000000007;
		y /= 2;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	kFact = numer = 1;

	if (K > (N /2 ))
		K = N - K;

	// numer의 값은 N! / (N - K)! 이다.
	for (int i = 0; i < K; ++i)
	{
		numer = numer * (N - i) % 1000000007;
		kFact = kFact * (K - i) % 1000000007;
	}

	ans = power(kFact, 1000000005);

	cout << numer * ans % 1000000007;
}
