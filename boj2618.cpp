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


int N;
int W;
pair<int, int> arr[1004];
int dp[1004][1004];
int solve[1004][1004];
vector<int> pout;

int dist(pair<int, int> a, pair<int, int> b)
{
	return abs(b.first - a.first) + abs(b.second - a.second);
}

int acci(int x, int y)
{
	if (x == W+1 || y == W+1)
		return 0;

	int& ret = dp[x][y];
	
	if (ret != -1)
		return ret;
	
	int a, b;

	a = acci(max(x, y) + 1, y) + dist(arr[x], arr[max(x, y) + 1]);
	b = acci(x, max(x, y) + 1) + dist(arr[y], arr[max(x, y) + 1]);

	if (a < b)
	{
		ret = a;
	}
	else
	{
		ret = b;
		solve[x][y] = 1;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	cin >> W;

	for (int i = 2; i < W+2; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	arr[0] = { 1,1 };
	arr[1] = { N,N };

	memset(dp, -1, sizeof(dp));

	cout << acci(0, 1) << "\n";
	for (int x=0,y=1 ; max(x,y) < W+1; )
	{
		cout << solve[x][y] + 1 << "\n";
		if (solve[x][y])
			y = max(x, y) + 1;
		else
			x = max(x, y) + 1;
	}

	return 0;
}