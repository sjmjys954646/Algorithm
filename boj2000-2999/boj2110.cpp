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

int N, C;
vector<long long> v;

long long Find(long long left, long long right)
{
	long long lo = 1;
	long long hi = right;
	long long ans = 0;

	while (lo <= hi)
	{
		long long pivot = (lo + hi) / 2;
		long long c = 1;
		long long cur = v[0];
		for (int i = 1; i < N ; i++)
		{
			if (v[i] - cur >= pivot)
			{
				c++;
				cur = v[i];
			}
		}

		if (c < C)
		{
			hi = pivot - 1;
		}
		else
		{
			ans = Max(ans, pivot);
			lo = pivot + 1;
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> N >> C;

	v.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	
	sort(v.begin(), v.end());
	cout << Find(0, v[N-1] - v[0]);

	return 0;
}
