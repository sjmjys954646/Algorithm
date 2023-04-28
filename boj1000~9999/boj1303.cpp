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

int N, M;

int arr[102][102];
int visited[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int depth = 0;


void dfs(int curY, int curX, int bef)
{
	depth++;
	visited[curY][curX] = 1;

	for (int i = 0; i < 4; i++)
	{
		int nX = curX + dx[i];
		int nY = curY + dy[i];

		if (nY < 0 || nX < 0 || nY >= M || nX >= N)
			continue;
		if (visited[nY][nX])
			continue;
		if (arr[nY][nX] != bef)
			continue;

		dfs(nY, nX, bef);
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	int B = 0;
	int W = 0;

	cin >> N >> M;

	rep(i, M)
	{
		string tmp;
		cin >> tmp;
		rep(j, N)
		{
			if (tmp[j] == 'B')
				arr[i][j] = 1;
			else
				arr[i][j] = -1;
		}
	}
	
	rep(i, M)
	{
		rep(j, N)
		{
			depth = 0;
			if (visited[i][j])
				continue;

			dfs(i, j, arr[i][j]);

			int p = depth;

			if (arr[i][j] == 1)
				B += p * p;
			else
				W += p * p;
		}
	}

	cout << W << " " << B;

	return 0;
}