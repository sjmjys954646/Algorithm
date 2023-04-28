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
#include <queue>
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

int arr[51][51];
bool check[51][51];
int plX[4] = { 1,0,-1,0 };
int plY[4] = { 0,1,0,-1 };

void dfs(int x, int y)
{
	check[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		if (arr[x + plX[i]][y + plY[i]]==1 &&check[x + plX[i]][ y + plY[i]] == false)
		{
			dfs(x + plX[i], y + plY[i]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;

	cin >> T;

	while (T--)
	{
		memset(arr, 0, sizeof(arr));
		memset(check, false, sizeof(check));
		int ans = 0;
		int M, N, K;

		cin >> M >> N >> K;

		int X, Y;

		for (int i = 0; i < K; i++)
		{
			cin >> X >> Y;
			arr[X][Y] = 1;
		}

		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] == 1 && check[i][j] == false)
				{
					dfs(i, j);
					ans++;
				}
				else
				{
					check[i][j] = true;
				}
			}
		}

		cout << ans<<"\n";
	}

	return 0;
}
