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
int dp[21];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int i = 4;i<=12;i++)
	{
		dp[i] = dp[i-1] + dp[i-2]+dp[i-3];
	}
	
	cin >> N;
	for(int i = 0;i<N;i++)
	{
		int t;
		cin >> t;
		cout<<dp[t]<<"\n";
	}
	
	return 0;
}