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

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	int N;
	string tmp;
	stack<char> s;
	stack<char> ss;
	int ans = 0;

	cin >> N;
	cin >> tmp;

	rep(i, N)
	{
		char t = tmp[i];
		if (t == 'R' || t == 'K')
		{
			if (t == 'R')
			{
				if (!s.empty() && s.top() == 'L')
				{
					s.pop();
					ans++;
				}
				else 
					break;
			}
			else if (t == 'K')
			{
				if (!ss.empty() && ss.top() == 'S')
				{
					ss.pop();
					ans++;
				}
				else
					break;
			}
		}
		else if (t == 'L' || t == 'S')
		{
			if (t == 'L')
			{
				s.push(t);
			}
			else if (t == 'S')
			{
				ss.push(t);
			}
		}
		else
			ans++;
	}

	cout << ans;



	return 0;
}