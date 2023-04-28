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
int curX, curY, d;
int dX[4] = { 0,1,0,-1 };
int dY[4] = {-1, 0, 1, 0};
int arr[55][55];
int visit[55][55];
int ans = 0;

int findUnclean()
{
	int ret = -1;
	int count = 0;
	int dir = d;
	while (true)
	{
		if (count == 4)
			break;

		dir--;
		if (dir == -1)
			dir = 3;

		int nX = curX + dX[dir];
		int nY = curY + dY[dir];

		if (nY < 0 || nX < 0 || nY >= N || nX >= M)
		{
			count++;
			continue;
		}
		if (visit[nY][nX] == 1 || arr[nY][nX] == 1)
		{
			count++;
			continue;
		}

		return dir;
	}
	return ret;
}

void sim()
{
	while (true)
	{
		if (visit[curY][curX] == 0)
		{
			visit[curY][curX] = 1;
			ans++;
		}
		int p = findUnclean();
		if (p == -1)
		{
			int nY = curY - dY[d];
			int nX = curX - dX[d];
			if (arr[nY][nX] == 1)
				break;
			else
			{
				curY = nY;
				curX = nX;
			}
		}
		else
		{
			d = p;
			int nY = curY + dY[d];
			int nX = curX + dX[d];
			curY = nY;
			curX = nX;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	cin >> curY >> curX >> d;

	rep(i, N)
	{
		rep(j, M)
		{
			cin >> arr[i][j];
		}
	}

	sim();

	cout << ans;

	return 0;
}