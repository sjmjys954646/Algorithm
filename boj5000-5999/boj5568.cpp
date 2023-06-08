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

int N, K;
vi v;
int tmp;
vi selected;
set<string> s;
int visited[12];

void dfs(int idx)
{
	if (selected.size() == K)
	{
		string p = "";
		for (auto i : selected)
		{
			p += to_string(i);
		}

		s.insert(p);
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (visited[i])
			continue;

		visited[i] = 1;
		selected.push_back(v[i]);
		dfs(i + 1);
		selected.pop_back();
		visited[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	rep(i, N)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	dfs(0);

	cout << s.size() << "\n";

	return 0;
}