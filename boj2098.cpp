#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

const double INF = 987654321;

int arr[18][18];
int N;
double dp[18][1<<16];

int TSP(int start, int visit)
{
  if(visit == (1<<N) - 1)
    return (arr[start][1]>0) ? arr[start][1] : INF; 
  
  double& ans = dp[start][visit];
  if(ans >= 0) 
    return ans;
  
  ans = INF;

  for(int i =1;i<=N;i++)
  {
    if(visit & (1<<(i-1)))
      continue;
    if(arr[start][i] <= 0)
      continue;
    double cand = arr[start][i] + TSP(i,visit + (1<<(i-1)));
    ans = min(ans,cand);
  }
  return ans;
}

int main() 
{
  memset(dp,-1,sizeof(dp));

  scanf("%d",&N);

  for(int i = 1;i<=N;i++)
  {
    for(int j = 1;j<=N;j++)
    {
      scanf("%d",&arr[i][j]);
    }
  }

  cout<<TSP(1,1);

	return 0;
}