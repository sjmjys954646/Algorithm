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

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

ll N;
ll X;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N;

	vi v;

	rep(i, 6)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	ll K = N / v[5] * v[5] + 1;

	for (ll i = K; i <= N; i++)
	{
		if (i % v[0] == 0)
		{
			X = X + i;
		}
		if (i % v[1] == 0)
		{
			X = X % i;
		}
		if (i % v[2] == 0)
		{
			X = X & i;
		}
		if (i % v[3] == 0)
		{
			X = X ^ i;
		}
		if (i % v[4] == 0)
		{
			X = X | i;
		}
		if (i % v[5] == 0)
		{
			X = X >> i;
		}

	}

	cout << X;



	return 0;
}