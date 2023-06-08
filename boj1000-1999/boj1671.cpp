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

struct same {
	int mag;
	int speed;
	int intel;
	int idx;
};


ll N, M;
bool visited[52];
ll A[52];
ll B[52];
vector<ll> arr[52];
vector<same> v;
ll a, b, c;
ll tmp;
ll ans = 0;

bool dfs(ll a)
{
	visited[a] = true;
	for (ll b : arr[a])
	{
		if (B[b] == -1 || !visited[B[b]] && dfs(B[b]))
		{
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;

		same t = { a,b,c,i };
		v.push_back(t);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == j)
				continue;

			if (v[i].mag >= v[j].mag && v[i].speed >= v[j].speed && v[i].intel >= v[j].intel)
			{
				if (v[i].mag == v[j].mag && v[i].speed == v[j].speed && v[i].intel == v[j].intel && i > j)
					continue;

				arr[i].push_back(j);
			}
		}
	}

	for (int i = 0; i <= N; i++)
	{
		if (A[i] != -1)
			continue;

		for (int j = 0; j < 2; j++)
		{
			memset(visited, 0, sizeof(visited));

			if (dfs(i))
				ans++;
		}
	}

	cout << N - ans;

	return 0;
}