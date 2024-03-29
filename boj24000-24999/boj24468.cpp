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

struct ball {
	int pos;
	int dir;
};

vector<ball> arr[1002];
vector<ball> v;
int L, N, T;
int pos;
string dirr;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> L >> N >> T;

	for (int i = 0; i < N; i++)
	{
		ball tmp;
		cin >> pos >> dirr;
		tmp = { pos, dirr ==  "R" ? 1 : -1 };
		v.push_back(tmp);
	}

	int ans = 0;

	for (int i = 1; i <= T; i++)
	{
		memset(arr, 0, sizeof(arr));
		for (int j = 0; j < N; j++)
		{
			int pos = v[j].pos + v[j].dir;

			if (pos == 0 || pos == L)
				v[j] = { pos,-v[j].dir };
			else
				v[j] = { pos, v[j].dir };

			arr[v[j].pos].push_back(v[j]);

			if (arr[v[j].pos].size() == 2)
			{
				arr[v[j].pos][0].pos = -arr[v[j].pos][0].pos;
				arr[v[j].pos][1].pos = -arr[v[j].pos][1].pos;
				ans++;
			}
		}
	}

	cout << ans;
	

	return 0;
}