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


int main()
{
	int dp[1001][1001];
	int N, K;

	cin >> N >> K;

	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i < 1001; i++)
	{
		dp[i][0] = 1;
		dp[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1]%10007 + dp[i - 1][j]%10007)%10007;
		}
	}

	cout << dp[N][K];

	return 0;
}