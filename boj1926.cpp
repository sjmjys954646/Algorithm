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
#include <deque>
#include <stack>
#include <cstring>
#include <list>
#include <set>
#include <string.h>
#include <map>
#include <limits.h>
#include <stdlib.h>
#include <typeinfo>
#include <bitset>

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

int N, M;
int arr[501][501];
int check[501][501];
int dY[4] = {-1,0,1,0};
int dX[4] = {0,-1,0,1};
int globSz = 0;
int bigAns = 0;

void bfs(int startY, int startX)
{
	queue<pii> q;
	check[startY][startX] = 1;
	q.push({startY, startX});

	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();

		bigAns = max(bigAns, globSz);

		for (int i = 0; i < 4; i++)
		{
			int nY = curY + dY[i];
			int nX = curX + dX[i];

			if (nY < 0 || nX < 0 || nY >= N || nX >= M)
				continue;
			if (arr[nY][nX] == 0)
				continue;
			if (check[nY][nX] == 1)
				continue;
				
			check[nY][nX] = 1;
			q.push({ nY, nX });
			globSz++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int ans = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 1 && check[i][j] == 0)
			{
				globSz = 1;
				ans++;
				bfs(i, j);
			}
		}
	}


	cout << ans << "\n" << bigAns;


	return 0;
}