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

ll ccw(const Point& a, const Point& b, const Point& c)
{
	return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

ll dist(Point a, Point b)
{
	return (a.y - b.y) * (a.y - b.y) + (a.x - b.x) * (a.x - b.x);
}

int arr[28];
int arr2[28];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	int N;
	int ans = 0;

	string tmp, tmp2;

	cin >> N;

	rep(i, N)
	{
		bool pos = true;
		memset(arr, 0, sizeof(arr));
		memset(arr2, 0, sizeof(arr2));

		cin >> tmp >> tmp2;
		for (int i = 0; i < tmp.size(); i++)
		{
			arr[tmp[i] - 'a'] += 1;
		}
		for (int i = 0; i < tmp2.size(); i++)
		{
			arr2[tmp2[i] - 'a'] += 1;
		}

		for (int i = 0; i <= 26; i++)
		{
			if (arr[i] != arr2[i])
				pos = false;
		}

		if (pos)
			cout << "Possible\n";
		else
			cout << "Impossible\n";

	}


	return 0;
}