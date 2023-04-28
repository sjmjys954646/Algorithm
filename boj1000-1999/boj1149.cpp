#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#define X first
#define Y second
using namespace std;

const int INF = 987654321;

int dp[1002][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> dp[i][j];
		}
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(j==0)
				dp[i][j] += min(dp[i - 1][1],dp[i-1][2]);
			else if(j==1)
				dp[i][j] += min(dp[i - 1][0], dp[i - 1][2]);
			else
				dp[i][j] += min(dp[i - 1][0], dp[i - 1][1]);
		}
	}

	int ans = min(dp[N - 1][0], dp[N - 1][1]);
	ans = min(ans, dp[N - 1][2]);

	cout << ans;

	return 0;
}