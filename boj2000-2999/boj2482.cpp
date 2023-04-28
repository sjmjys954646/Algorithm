#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

const int MOD = 1000000003;
int dp[1002][1002];

int main()
{
  int N, K;

  cin>>N>>K;

  for(int i = 1;i<=N;i++)
  {
    dp[i][0] = 1;
    dp[i][1] = i;
  }

  for(int i = 2;i<=N;i++)
  {
    for(int j = 2;j<=N;j++)
    {
      dp[i][j] = (dp[i-2][j-1] + dp[i-1][j])%MOD;
    }
  }

  int ans = (dp[N-3][K-1]+dp[N-1][K])%MOD;
  cout<<ans;

  return 0;
}