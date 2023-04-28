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



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int MatrixA[101][101];
	int MatrixB[101][101];

	int N, M, K;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MatrixA[i][j];
		}
	}

	cin >> M >> K;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cin >> MatrixB[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			int ans = 0;
			for (int t = 0; t < M; t++)
			{
				ans += MatrixA[i][t] * MatrixB[t][j];
			}
			cout << ans << " ";
		}
		cout << "\n";
	}



	return 0;
}//boj2740