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

int N, M, tmp;
vi v;
vi vv;
vi vvv;
vi selected;
int ans = INF;

void select(int idx, int fin)
{
	if (idx == fin)
	{
		int sum = 0;
		for (int i = 0; i < selected.size(); i++)
		{
			sum += pow(10, selected.size() - i - 1) * selected[i];
		}
		vvv.push_back(sum);
		return;
	}

	for (int i = 0; i < vv.size(); i++)
	{
		selected.push_back(vv[i]);
		select(idx + 1, fin);
		selected.pop_back();
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N;
	cin >> M;

	rep(i, M)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	for (int i = 0; i <= 9; i++)
	{
		bool exist = true;
		for (int j = 0; j < v.size(); j++)
		{
			if (i == v[j])
			{
				exist = false;
			}
		}
		if (exist)
			vv.push_back(i);
	}

	for (int i = 1; i <= 6; i++)
	{
		selected.clear();
		select(0, i);
	}

	for (int i = 0; i < vvv.size(); i++)
	{
		int p = vvv[i];
		int jalit = 0;
		while (p > 0)
		{
			p /= 10;
			jalit++;
		}
		if (vvv[i] == 0)
			jalit = 1;
		ans = min(ans, abs(vvv[i] - N) + jalit);
	}
	ans = min(ans, abs(100 - N));

	cout << ans;

	return 0;
}