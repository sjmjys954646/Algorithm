#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stdio.h>
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

int row;
int column;

int map[504][504];
int dp[504][504];

int ii[4] = { 1, 0, -1, 0 };
int jj[4] = { 0, 1, 0, -1 };

int dfs(int x, int y)
{

	if (x == row && y == column)
		return 1;

	if (dp[x][y] != -1) 
		return dp[x][y];


	dp[x][y] = 0;

	for (int i = 0; i < 4; i++)
	{


		int NX = x + ii[i];
		int NY = y + jj[i];


		if (NX < 1 || NX > row || NY < 1 || NY > column)
			continue;

		if (map[NX][NY] < map[x][y])
		{
			dp[x][y] += dfs(NX, NY);
		}
	}
	return dp[x][y];
}

int main(void)
{
	cin >> row >> column;

	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= column; j++)
		{
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}

	cout << dfs(1, 1);

	return 0;
}
