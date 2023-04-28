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

ll N;
ll primeNum[1500000];
priority_queue<ll,vector<ll>,greater<ll>> pq;
vi pp;
ll MOD = 2000003;

void Eratos()
{
	for (ll i = 2; i <= N; i++)
	{
		primeNum[i] = i;
	}

	for (ll i = 2; i <= sqrt(N); i++)
	{
		if (primeNum[i] == 0)
			continue;

		for (int j = i * i; j <= N; j += i)
			primeNum[j] = 0;
	}

	for (ll i = 2; i <= N; i++)
	{
		if (primeNum[i] != 0) {
			pq.push(i);
		}
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	N = 1499999;
	Eratos();

	cin >> N;

	ll ans = 1;
	
	while (N--)
	{
		ll tt = pq.top();
		pq.pop();
		ans = (ans %MOD * tt % MOD) %MOD;
		pq.push(tt * tt);
	}
	cout << ans;

	return 0;
}