//freopen("input.txt", "r", stdin);
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <list>
#include <set>
#include <string.h>
#include <map>
#include <limits.h>
#include <stdlib.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 987654321;

int arr[1002][1002];
int visited[1002][1002];
int dX[4] = { -1,0,1,0 };
int dY[4] = { 0,-1,0,1 };
int m, n;

void bfs(int startY, int startX)
{
	priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > q;
	q.push({ arr[startY][startX], { startY, startX } });

	while (!q.empty())
	{
		int y = q.top().second.first;
		int x = q.top().second.second;
		int cost = q.top().first;
		q.pop();

		if (visited[y][x] <= cost)
			continue;

		visited[y][x] = cost;


		if (y == m - 1 && x == n - 1)
			return;

		
		for (int i = 0; i < 4; i++)
		{
			int nY = y + dY[i];
			int nX = x + dX[i];

			if (nY < 0 || nX < 0 || nY >= m || nX >= n)
				continue;

			if (arr[nY][nX] == -1)
				continue;

			if (cost + arr[nY][nX] >= visited[nY][nX])
				continue;

			q.push({ cost + arr[nY][nX],{ nY,nX } });
		}
		/*for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << visited[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n"; cout << "\n";*/
	}

}

int main()
{

	cin >> m >> n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			visited[i][j] = INF;
		}
	}
	
	bfs(0, 0);

	if (visited[m - 1][n - 1] == INF || arr[0][0] == -1 || arr[m-1][n-1] == -1)
		cout << "-1";
	else
		cout << visited[m - 1][n - 1];

	return 0;
}