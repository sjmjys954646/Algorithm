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

ll sumA[1005];
ll sumB[1005];
ll arrA[1005];
ll arrB[1005];
ll T;
int aN, bN;
ll k;
vector<ll> vA;
vector<ll> vB;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	cin >> aN;

	rep1(i, aN)
	{
		cin >> arrA[i];
		sumA[i] = arrA[i] + sumA[i - 1];
	}

	cin >> bN;

	rep1(i, bN)
	{
		cin >> arrB[i];
		sumB[i] = arrB[i] + sumB[i - 1];
	}

	for (int i = 0; i <= aN; i++)
	{
		for (int j = i + 1 ; j <= aN; j++)
		{
			ll sA = sumA[j] - sumA[i];
			vA.push_back(sA);
		}
	}

	for (int i = 0; i <= bN; i++)
	{
		for (int j = i + 1; j <= bN; j++)
		{
			ll sB = sumB[j] - sumB[i];
			vB.push_back(sB);
		}
	}
	sort(vB.begin(), vB.end());

	ll ans = 0;
	for (int i = 0; i < vA.size(); i++)
	{
		auto itLow = lower_bound(vB.begin(), vB.end(), T - vA[i]) - vB.begin();
		auto itUp = upper_bound(vB.begin(), vB.end(), T - vA[i]) - vB.begin();

		ans += (itUp - itLow);
	}

	cout << ans;

	return 0;
}