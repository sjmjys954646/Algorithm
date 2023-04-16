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

const long long INF = 9876543210;

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

//
//ll arr[1000002];
//ll tree[4 * 1000002];
//ll N, M, K;
//ll order;
//ll a, b, c, d;
//
//ll init(ll start, ll end, ll node)
//{
//	if (start == end)
//		return tree[node] = arr[start];
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
//		return tree[node] = diff;;
//
//	ll mid = (start + end) / 2;
//
//	return tree[node] = update(start, mid, node * 2, index, diff) + update(mid + 1, end, node * 2 + 1, index, diff);
//}

vector<ll> v1;
vector<ll> v2;
ll N;
ll ans1 = INF;
ll ans2 = INF;
ll tmp;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N;

	rep(i, N)
	{
		cin >> tmp;
		if (abs(tmp) % 2 == 1)
			v1.push_back(tmp);
		else
			v2.push_back(tmp);
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int v1s = v1.size();
	int v2s = v2.size();

	for (int i = 0; i < v1s - 1; i++)
	{
		ans1 = min(ans1, v1[i + 1] - v1[i]);
	}
	
	for (int i = 0; i < v2s - 1; i++)
	{
		ans1 = min(ans1, v2[i + 1] - v2[i]);
	}
 	for (int i = 0; i < v1s; i++)
	{
		auto it = upper_bound(v2.begin(), v2.end(), v1[i]);
		if (it == v2.end())
			break;

		ans2 = min(ans2, *it  - v1[i]);
	}

	for (int i = 0; i < v2s; i++)
	{
		auto it = upper_bound(v1.begin(), v1.end(), v2[i]);
		if (it == v1.end())
			break;
		ans2 = min(ans2, *it - v2[i]);
	}
	if (ans1 == INF)
		ans1 = -1;
	if (ans2 == INF)
		ans2 = -1;

	cout << ans1 << " " << ans2;

	return 0;
}

