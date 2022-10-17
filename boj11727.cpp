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

int N;
int dp[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	dp[1] = 1;
	dp[2] = 3;
	
	for(int i = 3;i<=1000;i++)
	{
		dp[i] = (dp[i-1]%10007 + dp[i-2]*2%10007)%10007;
	}

	int t;
	cin >> t;
	cout<<dp[t]<<"\n";
	
	return 0;
}