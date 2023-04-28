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

int arr[1002];
int dp[1002];

int Inc(int num)
{
	int Max = 0;
	for (int i = 1; i <= num; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}
		Max = max(Max, dp[i]);
	}
	return Max;
}

int Dec(int num)
{
	int Max = 0;
	for (int i = 1; i <= num; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (arr[j] > arr[i] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}
		Max = max(Max, dp[i]);
	}
	return Max;
}

int main()
{
	int num;

	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		cin >> arr[i];
	}

	cout << Dec(num);

	return 0;
}