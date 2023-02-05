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


vector<ll> v;
map<ll, ll> m;
int whose[30]; // 1 jack 2 jill 3 sell
ll ans = INF;
int half;
int N;

void dfs(int idx, int fin)
{
	if (idx == fin)
	{
		ll jack = 0;
		ll jill = 0;
		ll sell = 0;

		rep(i, fin)
		{
			if (whose[i] == 1)
				jack += v[i];
			else if (whose[i] == 2)
				jill += v[i];
			else if (whose[i] == 3)
				sell += v[i];
		}

		if(m.count(jack-jill))
			m[jack - jill] = min(m[jack - jill],sell);
		else
			m[jack - jill] = sell;

		return;
	}

	for (int i = 1; i < 4; i++)
	{
		whose[idx] = i;
		dfs(idx + 1, fin);
		whose[idx] = 0;
	}
}

void ddfs(int idx, int fin)
{
	if (idx == fin)
	{
		ll jack = 0;
		ll jill = 0;
		ll sell = 0;

		for(int i = half;i<fin;i++)
		{
			if (whose[i] == 1)
				jack += v[i];
			else if (whose[i] == 2)
				jill += v[i];
			else if (whose[i] == 3)
				sell += v[i];
		}

		if (m.count(jill - jack))
			ans = min(ans, m[jill - jack] + sell);		

		return;
	}

	for (int i = 1; i < 4; i++)
	{
		whose[idx] = i;
		ddfs(idx + 1, fin);
		whose[idx] = 0;
	}
}


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	ll tmp;

	while (true)
	{
		ans = INF;
		m.clear();
		v.clear();

		cin >> N;
		if (N == 0)
			break;

		rep(i, N)
		{
			cin >> tmp;
			v.push_back(tmp);
		}

		half = N / 2;

		dfs(0, half);
		ddfs(half, N);

		cout << ans << "\n";
	}

	

	return 0;
}