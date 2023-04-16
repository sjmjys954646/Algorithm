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


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	int testcase;

	cin >> testcase;
	int index = 1;
	while (testcase--)
	{
		cout << "Case #" << index << ":\n";
		map<string, set<string>> m;
		int N;
		cin >> N;

		cin.ignore();
		rep(i, N)
		{
			string tmp;
			getline(cin, tmp);
			string year = tmp.substr(tmp.size() - 4,4);
			tmp = tmp.substr(0, tmp.size() - 5);

			if (m[tmp].size() == 0)
			{
				set<string> s;
				s.insert(year);
				m[tmp] = s;
			}
			else
			{
				m[tmp].insert(year);
			}
		}
		vector<string> ans;

		for (auto i : m)
		{
			if (i.second.size() < 5)
				ans.push_back(i.first);
		}

		sort(ans.begin(), ans.end());

		for (auto i : ans)
			cout << i << " ";
		cout << "\n";
		index++;
	}


	return 0;
}