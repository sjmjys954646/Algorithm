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

struct Connected
{
	int A;
	int B;
};

bool compare(Connected a1, Connected a2)
{
	return a1.A < a2.A;
}

int main()
{
	int num;
	int dp[501];
	int Max = 0;

	cin >> num;

	vector<Connected> arr(num + 1);

	for (int i = 1; i <= num; i++)
	{
		cin >> arr[i].A >> arr[i].B;
		dp[i] = 1;
	}

	sort(arr.begin(), arr.end(), compare);

	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[j].B < arr[i].B && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}
		Max = max(Max, dp[i]);
	}


	cout << num - Max;


	return 0;
}