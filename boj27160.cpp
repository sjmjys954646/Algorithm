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

int N, X;
int idx = 0;

int converter(string tmp)
{
	if (tmp == "STRAWBERRY")
	{
		return 1;
	}
	else if (tmp == "BANANA")
	{
		return 2;
	}
	else if (tmp == "LIME")
	{
		return 3;
	}
	else if(tmp == "PLUM")
	{
		return 4;
	}
}

int sum[5] = { 0, };
int ans = 0;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N;

	rep(i, N)
	{
		string tmp;
		cin >> tmp >> X;

		sum[converter(tmp)] +=X;
	}

	rep1(i, 4)
	{
		if (sum[i] == 5)
			ans++;
	}
	if (ans)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}