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
int arr[52][52];
int distArr[52][52];
int ans = 0;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	string tmp;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			distArr[i][j] = INF;

	}

	rep(i, N)
	{
		cin >> tmp;
		rep(j, N)
		{
			if (tmp[j] == 'Y')
			{
				arr[i][j] = 1;
				distArr[i][j] = 1;
			}
		}
	}


	for (int k = 0; k < N; k++) 
	{
		for (int i = 0; i < N; i++) 
		{
			for (int j = 0; j < N; j++) 
			{
				if (distArr[i][j] > distArr[i][k] + distArr[k][j])
				{
					distArr[i][j] = distArr[i][k] + distArr[k][j];
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		int cnt = 0;
		for (int j = 0; j < N; j++) 
		{
			if (i == j) 
				continue;

			if (distArr[i][j] <= 2) 
				cnt++;
		}
		ans = max(ans, cnt);
	}

	cout << ans << "\n";

	return 0;
}