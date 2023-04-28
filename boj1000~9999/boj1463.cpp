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

int dp[1000002];

int main()
{
	int num;

	cin >> num;
	dp[0] = 987654321;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i < 1000002; i++)
	{
		dp[i] = 987654321;
		if (i % 2 == 0)
		{
			dp[i] = min(dp[i],dp[i / 2] + 1);
		}
		if (i % 3 == 0)
		{
			dp[i] = min(dp[i],dp[i / 3] + 1);
		}
		if ((i - 1) % 2 == 0)
		{
			dp[i] = min(dp[i], dp[(i-1) / 2] + 2);
		}
		if ((i - 1) % 3 == 0)
		{
			dp[i] = min(dp[i], dp[(i - 1) / 3] + 2);
		}
		dp[i] = min(dp[i], dp[i - 1] + 1);
	}
	
	cout << dp[num];

	return 0;
}