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
#define Max(a,b) box < b ? b : box;
#define Min(a,b) box < b ? box : b;

using namespace std;

struct c
{
	int x;
	int y;
	int z;
};

int m, n, h, ans;
int box[101][101][101];
const int dx[] = { -1, 1, 0, 0, 0, 0 };
const int dy[] = { 0, 0, -1, 1, 0, 0 };
const int dz[] = { 0, 0, 0, 0, -1, 1 };
queue<c> q;

void bfs() {
	while (!q.empty()) 
	{
		int qX = q.front().x;
		int	qY = q.front().y;
		int	qZ = q.front().z;
		q.pop();

		for (int i = 0; i < 6; i++) 
		{
			int nX = qX + dx[i];
			int nY = qY + dy[i];
			int nZ = qZ + dz[i];
			if (nX < 0 || nX >= h || nY < 0 
				|| nY >= n || nZ < 0 || nZ >= m) 
				continue;

			if (box[nX][nY][nZ]) 
				continue;    

			box[nX][nY][nZ] = box[qX][qY][qZ] + 1; 
			q.push({ nX, nY, nZ });
		}
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			for (int k = 0; k < m; k++) 
			{
				cin >> box[i][j][k];
				if (box[i][j][k] == 1)
				{
					q.push({ i, j, k });
				}
			}
		}
	}

	bfs();

	for (int i = 0; i < h; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			for (int k = 0; k < m; k++) 
			{
				if (box[i][j][k] == 0) 
				{
					printf("-1\n");
					return 0;
				}
				if (ans < box[i][j][k]) 
					ans = box[i][j][k];
			}
		}
	}

	printf("%d\n", ans - 1);

	return 0;
}
