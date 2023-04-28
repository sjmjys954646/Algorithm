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

int w, h;
int arr[52][52];
int visit[52][52];
int ans = 0;
int dX[8] = {0,1,1,1,0,-1,-1,-1};
int dY[8] = {-1,-1,0,1,1,1,0,-1};

void bfs(int y, int x)
{
	ans++;
	queue<pii> q;
	visit[y][x] = 1;
	q.push({ y,x });

	while (!q.empty())
	{
		int curY = q.front().F;
		int curX = q.front().S;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nY = curY + dY[i];
			int nX = curX + dX[i];

			if (nX < 0 || nY < 0 || nX >= w || nY >= h)
				continue;
			if (arr[nY][nX] == 0)
				continue;
			if (visit[nY][nX] == 1)
				continue;

			q.push({ nY,nX });
			visit[nY][nX] = 1;
		}

	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;

	while(true)
	{
		ans = 0;
		memset(arr, 0, sizeof(arr));
		memset(visit, 0, sizeof(visit));

		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> arr[i][j];
			}
		}

		rep(i, h)
		{
			rep(j, w)
			{
				if (arr[i][j] == 0 || visit[i][j] == 1)
					continue;

				bfs(i, j);
			}
		}


		cout << ans << "\n";
	}


	return 0;
}