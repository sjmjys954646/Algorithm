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

int N, M, K;
vector<int> v;
int par[4000002];

int find(int x)
{
	if (par[x] == x)
		return x;
	else
		return par[x] = find(par[x]);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);

	par[y] = x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
		par[i] = i;
	
	rep(i, M)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	rep(i, K)
	{
		int tmp;
		cin >> tmp;

		auto k = upper_bound(v.begin(),v.end(),tmp);
		if (k == v.end())
		{
			k = v.begin();
		}

		int p = find(*k);
		cout << p << "\n";

		k = lower_bound(v.begin(), v.end(), p);

		if (k == v.end() - 1)
			continue;

		merge(*k, *(k++));


		/*for (int i = 1; i <= N; i++)
			cout << i << " : " << par[i] << "\n";
		cout << "\n";*/
	}

	return 0;
}