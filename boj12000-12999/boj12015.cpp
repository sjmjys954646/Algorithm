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
#include <queue>
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	int ans = 1;
	int num;
	int lis[1000002];

	cin >> N;

	cin >> lis[1];

	for (int i = 2; i <= N; i++)
	{
		cin >> num;

		if (lis[ans] < num)
		{
			lis[++ans] = num;
		}
		else
		{
			auto p = lower_bound(lis + 1, lis + ans, num);
			*p = num;
		}
	}
	cout << ans;

	return 0;
}
