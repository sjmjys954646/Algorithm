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

int N;
int arr[1025][1025];
int tmparr[1025][1025];

int pooling(int depth)
{
	if (depth == 1)
		return arr[0][0];

	int newi = 0;
	int newj = 0;
	for (int i = 0; i < depth; i+=2, newi++)
	{
		newj = 0;
		for (int j = 0; j < depth; j+=2, newj++)
		{
			vi v;
			v.push_back(arr[i][j]);
			v.push_back(arr[i+1][j]);
			v.push_back(arr[i][j+1]);
			v.push_back(arr[i + 1][j+1]);
			sort(v.begin(), v.end());
			int cur = v[2];
			tmparr[newi][newj] = cur;
		}
	}
	for (int i = 0; i < depth; i++)
	{
		for (int j = 0; j < depth; j++)
		{
			arr[i][j] = tmparr[i][j];
		}
	}

	return pooling(depth/2);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];


	cout << pooling(N);



	return 0;
}