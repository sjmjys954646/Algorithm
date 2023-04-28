#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int Min(int a, int b)
{
	return a < b ? a : b;
}

int Max(int a, int b)
{
	return a < b ? b : a;
}


int dp[102][100002];

int main()
{
	int N;
	int MaxWeigh;
	int Weigh;
	int Value;

	cin >> N >> MaxWeigh;

	vector<pair<int, int> > arr(N+1);

	for (int i = 1; i <= N; i++)
	{
		cin >> Weigh >> Value;
		arr[i] = make_pair(Weigh, Value);
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= MaxWeigh; j++)
		{
			dp[i][j] = dp[i-1][j];
			if(j>=arr[i].first)
			{							
				dp[i][j] = Max(dp[i][j], dp[i - 1][j-arr[i].first] + arr[i].second);
			}
		}
	}

	cout << dp[N][MaxWeigh];

	return 0;
}