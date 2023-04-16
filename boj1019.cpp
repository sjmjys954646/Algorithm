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

ll arr[11];
ll N;

void calc(ll n, ll pos)
{
	while (n > 0) 
	{
		arr[n % 10] += pos;
		n /= 10;
	}

}

void solve(ll start, ll end, ll pos)
{
	while (start % 10 != 0 && start <= end)
	{
		calc(start, pos);
		start++;
	}

	if (start > end)
		return;

	while (end % 10 != 9 && start <= end)
	{
		calc(end, pos);
		end--;
	}

	ll cnt = end / 10 - start / 10 + 1;

	for (int i = 0; i < 10; i++)
	{
		arr[i] += cnt * pos;
	}
	
	solve(start / 10, end / 10, pos * 10);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N;

	solve(1, N, 1);

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}

	

	return 0;
}