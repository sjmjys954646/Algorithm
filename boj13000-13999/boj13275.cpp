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


int arr[200002];
string tmp;
string s;

void manacher(string S, int N)
{
	int r = 0;
	int p = 0;
	for (int i = 0; i < N; i++)
	{
		if (i <= r)
			arr[i] = min(arr[2 * p - i], r - i);
		else
			arr[i] = 0;

		while (i - arr[i] - 1 >= 0 && i + arr[i] + 1 < N && S[i - arr[i] - 1] == S[i + arr[i] + 1])
			arr[i]++;

		if (r < i + arr[i])
		{
			r = i + arr[i];
			p = i;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> tmp;

	for (int i = 0; i < tmp.size(); i++)
	{
		s += '#';
		s += tmp[i];
	}
	s += '#';

	manacher(s, s.size());

	int ans = -1;

	rep(i, s.size())
		ans = max(ans, arr[i]);

	cout << ans;

	return 0;
}