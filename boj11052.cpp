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
int arr[10002]; 
int dp[10002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N;
	
	for(int i = 1;i<=N;i++)
	{
		cin>>arr[i];
	}
	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = max(arr[1]*2,arr[2]);
	
	for(int i = 3;i<=N;i++)
	{
		for(int j = i;j>=0;j--)
		{
			dp[i] = max(dp[i],arr[j]+dp[i-j]);
		}
	}
	cout<<dp[N];
	return 0;
}