#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;


int dp[1000002];

void go(int idx)
{
  if(idx == 0)
    return;
  cout<<idx<<" ";
  
    if(idx % 3 == 0 && dp[idx] == (dp[idx / 3] + 1))
    {
      go(idx / 3);
    }
    else if(idx % 2 == 0 && dp[idx] == (dp[idx / 2] + 1))
    {
      go(idx / 2);
    }
    else if(dp[idx] == (dp[idx - 1] + 1))
    {
      go(idx - 1);
    } 
}

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

    int a = dp[i / 2] + 1;
    int b = dp[i / 3] + 1;
    int c = dp[(i-1) / 2] + 2;
    int d = dp[(i - 1) / 3] + 2;
    int e = dp[i - 1] + 1;
		if (i % 2 == 0)
		{
			dp[i] = min(dp[i],a);
		}
		if (i % 3 == 0)
		{
			dp[i] = min(dp[i],b);
		}
		if ((i - 1) % 2 == 0)
		{
			dp[i] = min(dp[i], c);
		}
		if ((i - 1) % 3 == 0)
		{
			dp[i] = min(dp[i], d);
		}
		dp[i] = min(dp[i], e);

	}
	
	cout << dp[num]<<"\n";
  go(num);

    return 0;
}