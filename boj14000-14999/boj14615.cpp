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
vector<int> graph[100002];
vector<int> graph2[100002];
int visited[100002];
int pos;
bool posA[100002];
bool posB[100002];

void bfs1()
{
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	posA[1] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto i : graph[cur])
		{
			if (visited[i])
				continue;

			q.push(i);
			visited[i] = 1;
			posA[i] = true;
		}
	}
}

void bfs2()
{
	queue<int> q;
	q.push(N);
	visited[N] = 1;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto i : graph2[cur])
		{
			if (visited[i])
				continue;

			q.push(i);
			posB[i] = true;
			visited[i] = 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	rep(i, M)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph2[b].push_back(a);
	}

	bfs1();

	memset(visited, 0, sizeof(visited));

	bfs2();

	int testcase;
	cin >> testcase;
	while (testcase--)
	{
		cin >> pos;
		if (posA[pos] && posB[pos])
			cout << "Defend the CTP\n";
		else
			cout << "Destroyed the CTP\n";
	}

	return 0;
}