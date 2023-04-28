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

const int INF = 9876543210;

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

ll N, M, K;
vector<ll> tree;
vector<ll> a;
int aa[1000010];

long long init(int node, int start, int end) {
	if (start == end)
	{
		return tree[node] = a[start];
	}
	else
	{
		return tree[node] = max(init(node * 2, start, (start + end) / 2), init(node * 2 + 1, (start + end) / 2 + 1, end));
	}
}

void update(int node, int start, int end, int index, long long diff)
{
	if (index < start || index > end) return;

	tree[node] = tree[node] + diff;

	if (start != end)
	{
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

long long query(int node, int start, int end, int left, int right) {
	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
	{
		return tree[node];
	}

	return query(node * 2, start, (start + end) / 2, left, right) + query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	ll tmp, b, c;
	ll ans = 0;

	cin >> N;

	a.resize(N + 1);
	tree.resize(4 * N + 4);

	rep1(i, N)
	{
		cin >> b;
		aa[b] = i;
		//cout << b << " " << aa[b] << "\n";
	}

	rep1(i, N)
	{
		cin >> b;
		a[i] = aa[b];
		//cout << b << " " << aa[b] << "\n";
	}

	rep1(i, N)
	{
		int p = a[i];
		//cout << p << "\n";
		ans += query(1, 1, N, p+1, N);
		update(1, 1, N, p, 1);
	}

	cout << ans;

	return 0;
}