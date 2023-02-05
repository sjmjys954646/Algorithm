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

int N;
vector<Point> arr;

ll ccw(const Point& a, const Point& b, const Point& c)
{
	return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

ll dist(Point a, Point b)
{
	return (a.y - b.y) * (a.y - b.y) + (a.x - b.x) * (a.x - b.x);
}

bool check(const Point& a, const Point& b)
{
	ll c = ccw(*arr.begin(),a, b);

	if (c == 0)
	{
		return dist(*arr.begin(), a) < dist(*arr.begin(), b);
	}
	else
	{
		return c > 0;
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N;
	
	ll x, y;
	rep(i, N)
	{
		cin >> x >> y;
		Point p = { x,y };
		arr.push_back(p);
	}
	sort(arr.begin(), arr.end());
	sort(++arr.begin(), arr.end(), check);

	stack<int> s;
	s.push(0);
	s.push(1);

	for (int i = 2; i < N; i++)
	{
		while (s.size() >= 2) 
		{
			int first, second;
			second = s.top();
			s.pop();
			first = s.top();

			if (ccw(arr[first], arr[second], arr[i]) > 0) 
			{
				s.push(second);
				break;
			}
		}

		s.push(i);
	}

	cout << s.size();

	return 0;
}