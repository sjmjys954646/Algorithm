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

vector<pii> v;
string tmp;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> tmp;
	tmp = " " + tmp;

	int add = 0;
	int point = 0;
	for(int i = 0;i < tmp.size();i++)
	{
		if (tmp[i] == 'X')
		{
			add++;

			if (tmp[i - 1] == '.')
			{
				v.push_back({ 0, point });
				point = 0;
			}
			
		}
		else if(tmp[i] == '.')
		{
			point++;

			if (tmp[i - 1] == 'X')
			{
				v.push_back({ 1, add });
				add = 0;
			}
		}
	}

	if (point > 0)
		v.push_back({ 0, point });

	if (add > 0)
		v.push_back({ 1, add });

	bool pos = true;
	string ans = "";
	for (auto i : v)
	{
		if (i.first == 1 && i.second & 1)
		{
			pos = false;
			break;
		}
		else
		{
			if (i.first == 0)
			{
				for(int j = 0;j < i.second;j++)
					ans = ans + ".";
				continue;
			}
			else
			{
				if (i.second >= 4)
				{
					for (int j = 0; j < i.second / 4; j++)
						ans = ans + "AAAA";

					if (i.second % 4 > 0)
						ans = ans + "BB";
				}
				else
					ans = ans + "BB";
			}
		}
	}


	if (!pos)
		cout << "-1";
	else
		cout << ans;
	

	return 0;
}