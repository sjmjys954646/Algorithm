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

int dp[2001][2001];
vector<int> arr;

int findDP(int a, int b)
{
	int& ret = dp[a][b];
	
	if (b - a == 0 || b - a == 1)
	{
		return ret;
	}

	if (ret != -1)
		return ret; 

	if (arr[a] == arr[b])
	{
		ret = 1 * findDP(a + 1, b - 1);
	}
	else
		ret = 0;

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int Length;
	int Testcase;

	cin >> Length;

	for (int i = 0; i < Length; i++)
	{
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < Length; i++)
	{
		dp[i][i] = 1;
	}

	for (int i = 0; i < Length - 1; i++)
	{
		if (arr[i] == arr[i + 1])
			dp[i][i + 1] = 1;
		else
			dp[i][i + 1] = 0;
	}


	cin >> Testcase;

	while (Testcase != 0)
	{
		int a, b;

		cin>>a>>b;

		cout << findDP(a-1, b-1) << "\n";

		Testcase--;
	}


	return 0;
}