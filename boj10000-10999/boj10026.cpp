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

int arr[102][102];
int visited[102][102];
int N;
int ans = 0;
int ansRGB = 0;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0, 1,0,-1 };
string tmp;

void dfs(int y, int x)
{
	visited[y][x] = 1;
	int cur = arr[y][x];

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N)
			continue;
		if (visited[ny][nx])
			continue;
		if (arr[ny][nx] != cur)
			continue;

		dfs(ny, nx);
	}
}

void ndfs(int y, int x)
{
	visited[y][x] = 1;
	int cur = arr[y][x];
	bool sek = false;

	if (cur == 'B' - 'A')
		sek = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N)
			continue;
		if (visited[ny][nx])
			continue;
		
		if (sek)
		{
			if (arr[ny][nx] != cur)
				continue;
		}
		else
		{
			if (arr[ny][nx] == 'B' - 'A')
				continue;
		}

		ndfs(ny, nx);
	}
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N;

	rep(i, N)
	{
		cin >> tmp;
		rep(j, N)
		{
			arr[i][j] = tmp[j] - 'A';
		}
	}

	rep(i, N)
	{
		rep(j, N)
		{
			if (!visited[i][j])
			{
				ans++;
				dfs(i, j);
			}
		}
	}

	memset(visited, 0, sizeof(visited));

	rep(i, N)
	{
		rep(j, N)
		{
			if (!visited[i][j])
			{
				ansRGB++;
				ndfs(i, j);
			}
		}
	}

	cout << ans << ' ' << ansRGB;

	return 0;
}