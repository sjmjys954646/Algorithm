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

int arr[1000002];
int N, M;

int check()
{
	int ret = 0;
	int idx = 0;
	int bef = 0;
	while (true)
	{
		if (idx == N)
			break;

		if (arr[idx] == 1)
		{
			if (bef != 1)
				ret++;
			bef = 1;
		}
		else
		{
			if (bef == 1)
			{
				bef = 0;
			}
		}
		idx++;
	}
	return ret;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N >> M;

	rep(i, N)
		cin >> arr[i];
	
	int cur = check();;
	while (M--)
	{
		int tmp;
		cin >> tmp;

		if (tmp)
		{
			int a;
			cin >> a;
			a = a - 1;

			if (arr[a])
				continue;

			arr[a] = 1;
			cur++;
			if (a != 0)
			{
				if (arr[a - 1] == 1)
					cur--;
			}
			if (a != N - 1)
			{
				if (arr[a + 1] == 1)
					cur--;
			}
		}
		else
		{
			cout << cur << "\n";
		}
	}

	return 0;
}