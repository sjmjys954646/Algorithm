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
bool visited[1002];
int A[1002];
int B[1002];
vector<int> arr[1002];
int a, b, c;
int tmp;
int ans = 0;

bool dfs(int a)
{
	visited[a] = true;
	for (int b : arr[a])
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

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
	{
		cin >> a;
		rep(j, a)
		{
			cin >> b;
			arr[i].push_back(b);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		memset(visited, 0, sizeof(visited));

		if (dfs(i))
			ans++;
	}
	int p = 0;

	for (int i = 1; i <= N; i++)
	{
		memset(visited, 0, sizeof(visited));

		if (dfs(i))
		{
			p++;
			ans++;
		}

		if (p == K)
			break;
	}

	cout << ans;

	return 0;
}