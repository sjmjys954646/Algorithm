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
	double x, y;

	bool operator < (const Point& a)
	{
		if (y == a.y)
			return x < a.x;
		else
			return y < a.y;
	}
};

double ccw(const Point& a, const Point& b, const Point& c)
{
	return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

double dist(Point a, Point b)
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	float x1, y1, r1, x2, y2, r2; 
	const double pi = 3.14159265358979;

	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	Point a = { x1, y1 };
	Point b = { x2, y2 };

	double dd = sqrt(dist(a, b));
	double ans = 0;

	if (dd >= r1 + r2)
	{
		//외부
	}
	else if (dd <= abs(r1 - r2))
	{
		//내부
		ans += min(r1,r2) * min(r1, r2) * pi;
	}
	else
	{
		double aa = 2 * acos((dd * dd + r1 * r1 - r2 * r2) / (2 * dd * r1));
		double bb = 2 * acos((dd * dd + r2 * r2 - r1 * r1) / (2 * dd * r2));
		ans += (r1 * r1 * (aa - sin(aa)) + r2 * r2 * (bb - sin(bb))) / 2;
	}

	cout << fixed;
	cout.precision(3);
	cout << ans;

	return 0;
}