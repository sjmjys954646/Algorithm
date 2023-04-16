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

int R, C, K;
int ans = 0;
int arr[6][6];
int visited[6][6];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };


void dfs(int depth, int startY, int startX)
{
	if (startY  == 0 && startX == C-1)
	{
		if (depth == K)
			ans++;

		return;
	}

	visited[startY][startX] = 1;

	for (int i = 0; i < 4; i++)
	{
		int nX = startX + dx[i];
		int nY = startY + dy[i];

		if (nY < 0 || nX < 0 || nY >= R || nX >= C)
			continue;
		if (arr[nY][nX] == -1)
			continue;
		if (visited[nY][nX])
			continue;

		dfs(depth + 1, nY, nX);
		visited[nY][nX] = 0;
	}
}


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> R >> C >> K;

	rep(i, R)
	{
		string tmp;
		cin >> tmp;
		rep(j, C)
		{
			if (tmp[j] == 'T')
				arr[i][j] = -1;
		}
	}

	if(arr[R-1][0] != -1)
		dfs(1, R-1, 0);

	cout << ans;

	return 0;
}