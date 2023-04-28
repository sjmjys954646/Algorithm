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
#define X first
#define Y second
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

int graph[1002][1002];
int path[1002][1002][12];
int N, M;

int dX[4] = { 1,0,-1,0 };
int dY[4] = { 0,1,0,-1 };

struct a
{
	int x;
	int y;
	int w;
};


int bfs()
{
	queue<a> q;
	q.push({ 0,0, 0 });
	path[0][0][0] = 1;

	while (!q.empty())
	{
		int qX = q.front().x;
		int qY = q.front().y;
		int qW = q.front().w;
		q.pop();
		if (qX == N - 1 && qY == M - 1)
			return path[qX][qY][qW];

		for (int i = 0; i < 4; i++)
		{
			int nX = qX + dX[i];
			int nY = qY + dY[i];

			if (nX < 0 || nX >= N || nY < 0 || nY >= M)
				continue;
			if (path[nX][nY][qW])
				continue;

			if (graph[nX][nY] == 0)
			{
				path[nX][nY][qW] = path[qX][qY][qW] + 1;
				q.push({ nX,nY,qW });
			}
			else if (graph[nX][nY] == 1 && qW == 0)
			{
				path[nX][nY][1] = path[qX][qY][qW] + 1;
				q.push({ nX,nY,1 });
			}
		}
	}
	return -1;
}

int main()
{
	/*ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);*/

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &graph[i][j]);
		}
	}

	printf("%d", bfs());

	return 0;
}
