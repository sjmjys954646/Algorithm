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

vector<int> graph[100002];
int check[100002];
queue<int> q;
int N, K;
int tot = 0;
int ans = -1;

void bfs()
{
	queue<pii> q;

	q.push({ N,0 });
	check[N] = 1;

	while (!q.empty())
	{
		int cur = q.front().F;
		int cost = q.front().S;

		q.pop();

		check[cur] = 1;

		if (cur == K && ans == cost)
		{
			tot++;
		}

		if (cur == K  && ans == -1 )
		{
			ans = cost;
			tot++;
		}

		if (cur + 1 <= 100000 && !check[cur+1])
		{
			q.push({ cur + 1,cost + 1 });
		}
		if (cur - 1 >= 0 && !check[cur - 1])
		{
			q.push({ cur - 1,cost + 1 });
		}
		if (cur * 2 <= 100000 && !check[cur * 2])
		{
			q.push({ cur * 2,cost + 1 });
		}
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N >> K;

	bfs();

	cout << ans << '\n' << tot;

	return 0;
}