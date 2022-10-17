#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stdio.h>
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

int main()
{
	int N, K;
	int temp;
	int ans = 0;
	vector<int> arr;

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	for (int i = N - 1; i >= 0; i--)
	{
		if (arr[i] > K)
			continue;

		int Mok = K / arr[i];
		ans += Mok;
		K = K - Mok * arr[i];
	}
	
	cout << ans;

	return 0;
}

