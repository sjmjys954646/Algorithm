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

vi v;
int cache[300002];
int arr[300002];
int N;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N;

	int sum = 0;
	for (int i = 1; i <= 500; i++)
	{
		sum += i;
		arr[i] = arr[i - 1] + sum;

		if (arr[i] >= 300001)
			break;
		v.push_back(arr[i]);
	}

	for(int i = 1;i<=300000;i++)
		cache[i] = INF;

	cache[0] = 0;
	for (int i = 0; i <= 300000; i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (i < v[j])
				break;

			cache[i] = min(cache[i],cache[i - v[j]] + 1);
		}
	}
	
	cout << cache[N];

	return 0;
}