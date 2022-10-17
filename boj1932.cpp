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

int cache[501][501];
int arr[501][501];
int N;

int dp(int y,int x)
{
	if(y==N-1) return arr[y][x];
	int& ret=cache[y][x];
	if(ret!=-1)
		return ret;
	return ret = max(dp(y+1,x),dp(y+1,x+1)) + arr[y][x];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	memset(cache,-1,sizeof(cache));
	cin >> N;
	
	for(int i = 0;i<N;i++)
	{
		for(int j = 0;j<i+1;j++)
		{
			cin>>arr[i][j];
		}
	}
	cout<<dp(0,0);
	
	return 0;
}