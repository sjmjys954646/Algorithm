#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

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

struct Point {
	ll x, y;

	bool operator < (const Point& a)
	{
		if (y == a.y)
			return x < a.x;
		else
			return y < a.y;
	}
};

ll ccw(const Point& a, const Point& b, const Point& c)
{
	return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

ll dist(Point a, Point b)
{
	return (a.y - b.y) * (a.y - b.y) + (a.x - b.x) * (a.x - b.x);
}


int manhat(int startX, int startY, int endX, int endY)
{
	return abs(startX - endX) + abs(startY - endY);
}

int gcd(int x, int y)
{
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}

int N;
int board[11][11];
bool visited[11][11];
int ans = -1;

int sumVis()
{
	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j])
				sum++;
		}
	}

	return sum;
}

bool check(int curY, int curX)
{
	int nY = curY - 1;
	int nX = curX - 1;
	while (true)
	{
		if (nY < 0 || nX < 0 || nY >= N || nX >= N)
			break;

		if (visited[nY][nX] == 1)
			return false;

		nY--;
		nX--;
	}

	nY = curY - 1;
	nX = curX + 1;
	while (true)
	{
		if (nY < 0 || nX < 0 || nY >= N || nX >= N)
			break;

		if (visited[nY][nX] == 1)
			return false;

		nY--;
		nX++;
	}

	return true;
}

void dfs(int curY, int curX)
{
	if (curX >= N)
	{
		curY++;
		if ((curX & 1) == 1)
			curX = 0;
		else
			curX = 1;
	}

	if (curY == N)
	{
		ans = max(ans, sumVis());
		return;
	}

	if (board[curY][curX] == 0)
	{
		dfs(curY, curX + 2);
	}
	else
	{
		if (check(curY, curX))
		{
			visited[curY][curX] = 1;
			dfs(curY, curX + 2);
			visited[curY][curX] = 0;
			dfs(curY, curX + 2);
		}
		else
		{
			dfs(curY, curX + 2);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	rep(i, N)
	{
		rep(j, N)
		{
			cin >> board[i][j];
		}
	}

	dfs(-1, N);
	int p = ans;
	ans = -1;
	dfs(-1, N + 1);

	cout << ans + p;

	return 0;
}