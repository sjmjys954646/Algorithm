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

int N, M;
int tmp;
vi pibo;
int ans = 0;
int grundy[1002];
int grundycheck[20];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	grundy[2] = 1;

	for (int i = 3; i <= N; i++)
	{
		memset(grundycheck, 0, sizeof(grundycheck));
		int t = i - 2;
		for (int j = 0; j <= t; j++)
		{
			grundycheck[grundy[j]^grundy[t - j]] = 1;
		}

		for (int j = 0; j < 20; j++)
		{
			if (!grundycheck[j])
			{
				grundy[i] = j;
				break;
			}
		}

	}

	if (grundy[N])
		cout << 1;
	else
		cout << 2;


	return 0;
}