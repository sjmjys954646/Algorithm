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
int arr[1002][1002];
int dis[1002][1002];
int startY;
int startX;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

void bfs()
{
	queue<pair<pii, int>> q;
	q.push({ {startY,startX},1 });
	dis[startY][startX] = 0;
	
	while (!q.empty())
	{
		auto k = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nY = k.first.first + dy[i];
			int nX = k.first.second + dx[i];

			if (nY < 0 || nX < 0 || nY >= N || nX >= M)
				continue;

			if (dis[nY][nX] != -1)
				continue;

			if (arr[nY][nX] == 0)
				continue;

			dis[nY][nX] = k.second;
			q.push({ {nY,nX},k.second + 1 });
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dis, -1, sizeof(dis));

	cin >> N >> M;

	rep(i, N)
	{
		rep(j, M)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				startY = i;
				startX = j;
			}
		}
	}

	bfs();

	rep(i, N)
	{
		rep(j, M)
		{
			if (arr[i][j] == 0)
				cout << 0 << " ";
			else
				cout << dis[i][j] << " ";
		}
		cout << "\n";
	}

	
	return 0;
}