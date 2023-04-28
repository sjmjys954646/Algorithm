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
int arr[1002][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N,ans;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}

	for(int j = 0;j<3;j++)
  {
    for(int i = 0;i<3;i++)
    {
      if(i==j)
        dp[0][i] = arr[0][i];
      else
        dp[0][i] = INF;
    }
    for(int i = 1; i<N; i++)
    {
      dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
      dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
      dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
    }   
    for(int i = 0;i<3;i++)
    {
      if(i==j)
        continue;
      ans = min(ans,dp[N-1][i]);
    }
  }

	cout << ans;

	return 0;
}