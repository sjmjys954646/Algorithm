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

int testcase;
ll N, M, K;
ll a, b, c;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> testcase;
	
	while (testcase--)
	{
		map<char, int> m;
		map<char, int> mm;
		cin >> N >> M;
		string tmp;
		string ttmp;
		cin >> tmp;
		cin >> ttmp;

		bool pos = true;
		for (int i = 0; i < N; i++)
		{
			if (i >= N - M && i <= M - 1)
			{
				if (tmp[i] != ttmp[i])
					pos = false;
			}
			else
			{
				if (!m.count(tmp[i]))
					m[tmp[i]] = 1;
				else
					m[tmp[i]]++;

				if (!mm.count(ttmp[i]))
					mm[ttmp[i]] = 1;
				else
					mm[ttmp[i]]++;
			}
		}

		if (m != mm)
		{
			pos = false;
		}
		
		if (pos)
			cout << "YES\n";
		else
			cout << "NO\n";

	}


	return 0;
}