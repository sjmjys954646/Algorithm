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

vector<int> v;
int w, n;
pair<int,int> pos[800000];
int tmp;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> w >> n;

	rep(i, n)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	bool pp = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int sum = v[i] + v[j];
			pos[sum] = { i,j };

			if (sum >= w)
				continue;

			if (pos[w - sum].F + pos[w - sum].S != 0)
			{
				if (pos[w - sum].F == i)
					continue;
				if (pos[w - sum].F == j)
					continue;
				if (pos[w - sum].S == i)
					continue;
				if (pos[w - sum].S == j)
					continue;
				pp = true;
			}
			if (pp)
				break;
		}
		if (pp)
			break;
	}

	if (pp)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}