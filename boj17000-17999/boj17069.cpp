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

int N;
ll cache[34][34][3];
// 0 가로 
// 1 세로
// 2 대각
ll arr[34][34];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	rep1(i, N)
	{
		rep1(j, N)
		{
			cin >> arr[i][j];
		}
	}

	cache[1][2][0] = 1;

	rep1(i, N)
	{
		rep1(j, N)
		{
			// 0
			if (arr[i][j + 1] == 0)
				cache[i][j + 1][0] += (cache[i][j][2] + cache[i][j][0]);

			// 1
			if (arr[i + 1][j] == 0)
				cache[i + 1][j][1] += (cache[i][j][2] + cache[i][j][1]);

			// 2
			if (arr[i + 1][j + 1] == 0 && arr[i+1][j] == 0 && arr[i][j+1] == 0)
				cache[i + 1][j + 1][2] += (cache[i][j][2] + cache[i][j][1] + cache[i][j][0]);

		}
	}

	ll ans = 0;

	rep(i, 3)
		ans += cache[N][N][i];

	cout << ans;

	return 0;
}