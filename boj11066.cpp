#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

using namespace std;

int Min(int a, int b)
{
	return a < b ? a : b;
}

int Max(int a, int b)
{
	return a < b ? b : a;
}


int main()
{
	int num;
	int tmp;
	int arr[502];
	int dp[502][502];
	int testcase = 0;
	cin >> testcase;

	for (int t = 0 ; t < testcase; t++)
	{
		cin >> num;

		for (int i = 1; i <= num; i++)
		{
			cin >> tmp;
			arr[i] = arr[i - 1] + tmp;
		}

		for (int i = 1; i <= num; i++)
		{
			for (int j = 1; j <= num; j++)
			{
				if (i == j)
					dp[i][j] = 0;
				else
					dp[i][j] = 987654321;
			}
		}

		for (int k = 1; k < num; k++)
		{
			for (int i = 1; i <= num - k; i++)
			{
				for (int j = i; j<i + k; j++)
				{
					dp[i][i + k] = Min(dp[i][i + k], dp[i][j] + dp[j + 1][i + k]);
				}
				dp[i][i + k] += arr[i + k] - arr[i - 1];
			}
		}


		cout << dp[1][num]<<"\n";
	}

	


	return 0;
}