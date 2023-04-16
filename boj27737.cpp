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

int N, M, K;
int arr[102][102];
int visited[102][102];
vi v;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,-1,0,1 };

int bfs(int startY,int startX)
{
	int depth = 0;
	queue<pii> q;
	q.push({ startY, startX });
	visited[startY][startX] = 1;

	while (!q.empty())
	{
		int curY = q.front().first;
		int curX = q.front().second;
		q.pop();
		depth++;

		for (int i = 0; i < 4; i++)
		{
			int nY = curY + dy[i];
			int nX = curX + dx[i];

			if (nY < 0 || nX < 0 || nY >= N || nX >= N)
				continue;
			if (visited[nY][nX] == 1 || arr[nY][nX] == 1)
				continue;

			visited[nY][nX] = 1;
			q.push({ nY,nX });
		}
	}

	return depth;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N >> M >> K;

	int mush = 0;
	int tmp;

	rep(i, N)
	{
		rep(j, N)
		{
			cin >> tmp;
			arr[i][j] = tmp;
			visited[i][j] = tmp;
			if (tmp == 1)
				mush++;
		}
	}

	if (mush == N * N)
		cout << "IMPOSSIBLE";
	else
	{
		rep(i, N)
		{
			rep(j, N)
			{
				if (!visited[i][j])
				{
					v.push_back(bfs(i, j));
				}
			}
		}

		int ans = 0;
		for (auto i : v)
		{
			ans += i / K;
			if (i % K != 0)
				ans++;
		}

		if (ans > M)
			cout << "IMPOSSIBLE";
		else
			cout << "POSSIBLE\n" << M - ans;
	}

	
	

	return 0;
}