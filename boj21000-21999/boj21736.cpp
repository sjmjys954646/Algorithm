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
char arr[602][602];
int visited[602][602];
int startY;
int startX;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int ans;

void bfs()
{
	queue<pii> q;
	q.push({ startY,startX });
	visited[startY][startX] = 1;

	while (!q.empty())
	{
		auto k = q.front();
		q.pop();

		if (arr[k.first][k.second] == 'P')
		{
			ans++;
		}

		for (int i = 0; i < 4; i++)
		{
			int nY = k.first + dy[i];
			int nX = k.second + dx[i];

			if (nY < 0 || nX < 0 || nY >= N || nX >= M)
				continue;

			if (visited[nY][nX])
				continue;

			if (arr[nY][nX] == 'X')
				continue;

			visited[nY][nX] = 1;
			q.push( {nY,nX});
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	rep(i, N)
	{
		rep(j, M)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'I')
			{
				startY = i;
				startX = j;
			}
		}
	}

	bfs();

	if (ans)
		cout << ans;
	else
		cout << "TT";

	return 0;
}