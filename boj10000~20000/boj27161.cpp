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

int invertor(string tmp)
{
	if (tmp == "CLOCK")
	{
		return 1;
	}
	else if (tmp == "WATCH")
	{
		return 2;
	}
	else if (tmp == "HOURGLASS")
	{
		return 3;
	}
}

int idx = 1;
int N;
int dir = 1;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N;

	rep(i, N)
	{
		string tmp;
		int a;
		bool time = false;
		bool dongi = false;

		cin >> tmp >> a;

		if (invertor(tmp) == 3)
			time = true;
		if (idx == a)
			dongi = true;

		if (time && dongi)
		{
			cout << idx << " " << "NO\n";
		}
		else if (time)
		{
			dir *= -1;
			cout << idx << " " << "NO\n";
		}
		else if (dongi)
		{
			cout << idx << " " << "YES\n";
		}
		else
		{
			cout << idx << " " << "NO\n";
		}

		idx += dir;
		if (idx == 0)
			idx = 12;

		if (idx == 13)
			idx = 1;
	}
	

	return 0;
}