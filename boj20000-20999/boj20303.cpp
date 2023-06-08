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
int arr[30003];
int par[30003];
int tmp;
int cost[30003];
int weight[30003];
int a, b;
int cache[30003][3002];
map<int, int> m;
int idx = 0;

int find(int x)
{
	if (par[x] == x)
		return x;
	else
		return par[x] = find(par[x]);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x > y)
		swap(x, y);

	par[y] = x;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	rep1(i, N)
	{
		cin >> tmp;
		arr[i] = tmp;
		par[i] = i;
	}

	rep(i, M)
	{
		cin >> a >> b;
		merge(a, b);
	}

	rep1(i, N)
	{
		int t = find(i);
		if (m.count(t) == 0)
		{
			idx++;
			m[t] = idx;
		}

		weight[m[t]] += arr[i];
		cost[m[t]]++;
	}

	/*for(int i = 0;i<= idx;i++)
	{
		cout << weight[i] << " ";
	}
	cout << "\n";

	for (int i = 0; i <= idx; i++)
	{
		cout << cost[i] << " ";
	}
	cout << "\n";*/

	rep1(i, idx)
	{
		rep1(j, K)
		{
			int curW = cost[i];
			int curVal = weight[i];

			if (curW <= j)
			{
				cache[i][j] = max(cache[i - 1][j - curW] + curVal, cache[i - 1][j]);
			}
			else
			{
				cache[i][j] = cache[i - 1][j];
			}
		}
	}

	cout << cache[idx][K - 1];


	return 0;
}