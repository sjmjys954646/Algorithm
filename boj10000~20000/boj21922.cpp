// freopen("input.txt", "r", stdin);
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

int arr[2002][2002];
int N, M;
vector<pii> aircon;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int check[2002][2002][4];
int dirOp[4] = {2, 3, 0, 1};

int converter(int cur, int dir)
{
	if (cur == 3)
	{
		if (dir == 0)
			return 1;
		else if (dir == 1)
			return 0;
		else if (dir == 2)
			return 3;
		else if (dir == 3)
			return 2;
	}
	else if (cur == 4)
	{
		if (dir == 0)
			return 3;
		else if (dir == 1)
			return 2;
		else if (dir == 2)
			return 1;
		else if (dir == 3)
			return 0;
	}
	return 0;
}

void bfs(int startY, int startX)
{
	for (int i = 0; i < 4; i++)
	{
		check[startY][startX][i] = 1;
	}
	queue<pair<pii, int>> q;
	for (int i = 0; i < 4; i++)
	{
		q.push({{startY, startX}, i});
	}

	while (!q.empty())
	{
		int startY = q.front().F.F;
		int startX = q.front().F.S;
		int dir = q.front().S;
		q.pop();

		int nY = startY + dy[dir];
		int nX = startX + dx[dir];

		if (nY < 0 || nX < 0 || nY >= N || nX >= M)
			continue;
		if (check[nY][nX][dir] == 1)
			continue;

		check[nY][nX][dir] = 1;

		if (arr[nY][nX] == 0)
			q.push({{nY, nX}, dir});
		else if (arr[nY][nX] == 1 || arr[nY][nX] == 2)
		{
			if (arr[nY][nX] == 1)
			{
				if (dir == 1 || dir == 3)
				{
					check[nY][nX][dir] = 1;
					continue;
				}
				else
					q.push({{nY, nX}, dir});
			}
			else if (arr[nY][nX] == 2)
			{
				if (dir == 0 || dir == 2)
				{
					check[nY][nX][dir] = 1;
					continue;
				}
				else
					q.push({{nY, nX}, dir});
			}
		}
		else
		{
			q.push({{nY, nX}, converter(arr[nY][nX], dir)});
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(check, 0, sizeof(check));

	cin >> N >> M;

	rep(i, N)
	{
		rep(j, M)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 9)
			{
				aircon.push_back({i, j});
			}
		}
	}

	for (int i = 0; i < aircon.size(); i++)
	{
		int airconY = aircon[i].F;
		int airconX = aircon[i].S;

		bfs(airconY, airconX);
	}

	int ans = 0;
	rep(i, N)
	{
		rep(j, M)
		{
			rep(k, 4)
			{
				if (check[i][j][k] == 1)
				{
					ans++;
					k = 4;
				}
			}
		}
	}

	cout << ans;

	return 0;
}