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
#include <stdlib.h>
#define X first
#define Y second
using namespace std;

const int INF = 987654321;

int N, M;
int graph[101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int u1, u2, w;
		cin >> u1 >> u2 >> w;
		if(!graph[u1][u2])
			graph[u1][u2] = w;
		else
			graph[u1][u2] = min(graph[u1][u2], w);
	}


	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (graph[j][i] == 0)
				continue;

			for (int k = 1; k <= N; k++)
			{
				if (graph[i][k] == 0 || j == k)
					continue;

				if (graph[j][k] == 0 || graph[j][k] > graph[j][i] + graph[i][k])
					graph[j][k] = graph[j][i] + graph[i][k];
			}
		}
	}


	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cout << graph[i][j] << " ";
		cout << "\n";
	}

	return 0;
}