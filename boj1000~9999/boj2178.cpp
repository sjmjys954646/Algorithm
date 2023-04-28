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

int graph[101][101];
bool check[101][101];
int plX[4] = { 1,0,-1,0 };
int plY[4] = { 0,1,0,-1 };
queue<pair<int, int> > q;
int N, M;

void BFS()
{
	while (!q.empty())
	{
		int frontX = q.front().X;
		int frontY = q.front().Y;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = frontX + plX[i];
			int ny = frontY + plY[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;

			if (check[nx][ny] == false
				&& graph[nx][ny] == 1)
			{
				q.push({ nx,ny});
				check[nx][ny] = true;
				graph[nx][ny] = graph[frontX][frontY] + 1;
			}
		}
	}
}

int main()
{
	//ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &graph[i][j]);
		}
	}
	graph[0][0] = 2;
	q.push({ 0,0 });
	BFS();

	cout << graph[N - 1][M - 1] - 1;

	return 0;
}
