#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <iostream>


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


vector<pair<ll, ll>> p;
vector<pair<ll,ll>> v;
ll a, b;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;

	cin >> testcase;

	while (testcase--)
	{
		p.clear();
		p.clear();
		v.clear();

		rep(i, 4)
		{
			cin >> a >> b;
			p.push_back({ a,b });
		}

		sort(p.begin(), p.end());

		v.push_back({ p[1].first - p[0].first, p[1].second - p[0].second });
		v.push_back({ p[2].first - p[0].first, p[2].second - p[0].second });
		v.push_back({ p[3].first - p[1].first, p[3].second - p[1].second });
		v.push_back({ p[3].first - p[2].first, p[3].second - p[2].second });

		bool pos = true;

		ll p = v[0].first * v[0].first + v[0].second * v[0].second;
		for(int i = 1;i < 4;i++)
		{
			if (p != (v[i].first * v[i].first + v[i].second * v[i].second))
			{
				pos = false;
			}
		}

		if (v[0].first * v[1].first + v[0].second * v[1].second != 0)
			pos = false;
		if (v[0].first * v[2].first + v[0].second * v[2].second != 0)
			pos = false;
		if (v[1].first * v[3].first + v[1].second * v[3].second != 0)
			pos = false;
		if (v[2].first * v[3].first + v[2].second * v[3].second != 0)
			pos = false;

		if (pos)
			cout << "1\n";
		else
			cout << "0\n";

	}

	

	return 0;
}