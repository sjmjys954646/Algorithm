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

	int N, K;

	cin >> N >> K;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	long long left = 1;
	long long right = 9876543210;
	long long ans = 0;;
	while (left <= right)
	{
		long long sum = 0;
		
		long long pivot = (left + right) / 2;


		for (int i = 0; i < N; i++)
		{
			if (v[i] - pivot > 0)
				sum += v[i] - pivot;
		}
	
		if (sum >= K)
		{
			ans = Max(ans, pivot);
			left = pivot + 1;
		}
		else
		{
			right = pivot - 1;
		}
	}
	cout << ans;

	return 0;
}
