#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stdio.h>
#include <string>
#include<string.h>
#include <math.h>
#include <map>
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

int m[101];
int c[101];
int dp[101][10001];

int Memory(int num, int cost)
{
	if (num > 100)
		return 0;

	int& ret = dp[num][cost];

	if (ret != -1)
		return ret;

	ret = Memory(num + 1, cost);
	if (c[num] <= cost)
		ret = Max(ret, m[num] + Memory(num + 1, cost - c[num]));
	
	return ret;

}

int main()
{
	int N, M;

	cin >> N >> M;

	for(int i = 0;i<N;i++)
	{
		cin >> m[i];
	}
	
	for (int i = 0; i < N; i++)
	{
		cin >> c[i];
	}
	memset(dp, -1, sizeof(dp));

	for (int i = 0;; i++)
	{
		if (Memory(0, i) >= M)
		{
			cout << i;
			break;
		}
	}
	return 0;
}