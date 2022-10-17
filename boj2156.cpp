#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a < b ? b : a;
}

int dp[10001][3];

int main()
{
	int num;
	int arr[10001];
	int ans = 0;

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}

	dp[0][1] = arr[0];
	dp[1][0] = arr[0];
	dp[1][1] = arr[1];
	dp[1][2] = arr[0] + arr[1];

	for (int i = 2; i < 10001; i++)
	{
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][0] = max(dp[i][0], dp[i - 1][2]);
		dp[i][1] = dp[i - 1][0] + arr[i];
		dp[i][2] = dp[i - 1][1] + arr[i];
	}
	ans = max(dp[num-1][0], dp[num-1][1]);
	ans = max(ans, dp[num-1][2]);

	cout << ans;

	return 0;
}




