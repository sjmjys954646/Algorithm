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

int N, a, b;
int visited[1000002];
const int maxi = 1000001;

int bfs()
{
	queue<pii> q;
	q.push({ 0, 0 });
	visited[0] = 1;

	while (!q.empty())
	{
		auto k = q.front();
		q.pop();

		if (k.first == N)
		{
			return k.second;
		}

		if (k.first + 1 + a < maxi && !visited[k.first + 1 + a])
		{
			q.push({ k.first + 1 + a,k.second + 1 });
			visited[k.first + 1 + a] = 1;
		}

		if (k.first + 1 + b < maxi &&  !visited[k.first + 1 + b])
		{
			q.push({ k.first + 1 + b,k.second + 1 });
			visited[k.first + 1 + b] = 1;
		}

		if (!visited[k.first + 1])
		{
			q.push({ k.first + 1, k.second + 1 });
		}
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> a >> b;

	cout << bfs();

	
	return 0;
}