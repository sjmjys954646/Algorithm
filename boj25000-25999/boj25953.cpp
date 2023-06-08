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

const ll INF = 9876543210;

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

//ll arr[100002];
//ll tree[4 * 100002];
//ll N, M, K;
//ll order;
//ll a, b, c, d;
//
//ll init(ll start, ll end, ll node)
//{
//	if (start == end)
//		return tree[node] = arr[start] - arr[start - 1];
//
//	ll mid = (start + end) / 2;
//
//	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
//}
//
//ll query(ll start, ll end, ll node, ll left, ll right)
//{
//	if (left > end || right < start)
//		return 0;
//
//	if (left <= start && end <= right)
//		return tree[node];
//
//	ll mid = (start + end) / 2;
//
//	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
//}
//
//ll update(ll start, ll end, ll node, ll index, ll diff)
//{
//	if (index < start || end < index)
//		return tree[node];
//
//	if (start == end)
//		return tree[node] += diff;;
//
//	ll mid = (start + end) / 2;
//
//	return tree[node] = update(start, mid, node * 2, index, diff) + update(mid + 1, end, node * 2 + 1, index, diff);
//}

ll N, T, M, W;
ll S, E;
ll a, b, c;
ll cache[1002][10002];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N >> T >> M;

	cin >> S >> E;

	for (int i = 0; i <= 1001; i++)
	{
		for (int j = 0; j <= 10001; j++)
			cache[i][j] = INF;
	}

	cache[0][S] = 0;

	for (int i = 1; i <= T; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cache[i][j] = cache[i - 1][j];
 		}

		for (int j = 0; j < M; j++)
		{
			cin >> a >> b >> c;

			if (cache[i - 1][a] != INF)
				cache[i][b] = min(cache[i][b], cache[i - 1][a] + c);

			if (cache[i - 1][b] != INF)
				cache[i][a] = min(cache[i][a], cache[i - 1][b] + c);

		}

	}
	if (cache[T][E] == INF)
		cache[T][E] = -1;

	cout << cache[T][E];


	return 0;
}

