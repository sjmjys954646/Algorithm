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

	long long N;
	long long K;

	cin >> N >> K;

	long long left = 1;
	long long right = K;
	long long mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		long long c = 0;

		for (int i = 1; i <= N; i++)
		{
			c += Min(N, mid / i);
		}


		if (c < K)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}

	}
	cout << left;

	return 0;
}
