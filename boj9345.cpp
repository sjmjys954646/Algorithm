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

ll Sseg[100002 * 4];
ll Bseg[100002 * 4];
ll arr[100002];
ll N, M, K;
ll order;
ll a, b, c, d;

ll Bupdate(ll pos, ll val, ll node, ll x, ll y)
{
	if (pos < x || y < pos)
		return Bseg[node];
	if (x == y)
		return Bseg[node] = val;

	ll mid = (x + y) / 2;

	return Bseg[node] = max(Bupdate(pos, val, node * 2, x, mid), Bupdate(pos, val, node * 2 + 1, mid + 1, y));
}

ll Bquery(ll lo, ll hi, ll node, ll x, ll y)
{
	if (y < lo || hi < x)
		return -1;
	if (lo <= x && y <= hi)
		return Bseg[node];

	ll mid = (x + y) / 2;

	return max(Bquery(lo, hi, node * 2, x, mid), Bquery(lo, hi, node * 2 + 1, mid + 1, y));
}

ll Supdate(ll pos, ll val, ll node, ll x, ll y)
{
	if (pos < x || y < pos)
		return Sseg[node];
	if (x == y)
		return Sseg[node] = val;

	ll mid = (x + y) / 2;

	return Sseg[node] = min(Supdate(pos, val, node * 2, x, mid), Supdate(pos, val, node * 2 + 1, mid + 1, y));
}

ll Squery(ll lo, ll hi, ll node, ll x, ll y)
{
	if (y < lo || hi < x)
		return 1000000001;
	if (lo <= x && y <= hi)
		return Sseg[node];

	ll mid = (x + y) / 2;

	return min(Squery(lo, hi, node * 2, x, mid), Squery(lo, hi, node * 2 + 1, mid + 1, y));
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	int testcase;

	cin >> testcase;

	while (testcase--)
	{
		memset(Sseg, 0, sizeof(Sseg));
		memset(Bseg, 0, sizeof(Bseg));

		cin >> N >> M;

		rep(i, N)
		{
			arr[i] = i;
			Bupdate(i, i, 1, 0, N - 1);
			Supdate(i, i, 1, 0, N - 1);
		}


		rep(i, M)
		{
			cin >> order >> b >> c;

			if (!order)
			{
				Bupdate(b, arr[c], 1, 0, N - 1);
				Bupdate(c, arr[b], 1, 0, N - 1);
				Supdate(b, arr[c], 1, 0, N - 1);
				Supdate(c, arr[b], 1, 0, N - 1);

				swap(arr[b], arr[c]);
			}
			else
			{
				if (Bquery(b, c, 1, 0, N - 1) == c && Squery(b, c, 1, 0, N - 1) == b)
					cout << "YES\n";
				else
					cout << "NO\n";

			}
			
		}
	}

	
	

	return 0;
}


