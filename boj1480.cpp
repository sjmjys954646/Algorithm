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

long long arr[21];
int N, M, C;
long long dp[1 << 14][12][21];
//사용한 보석 , 현재 가방 idx, 가방 남은 용량 = 보석의 최대 개수

long long TSP(int visit, int idx, int capacity)
{

	if (visit == (1 << N) - 1 || idx == M)
		return 0;

	long long& ret = dp[visit][idx][capacity];

	if (ret >= 0)
		return ret;

	ret = 0;

	for (int i = 0; i < N; i++)
	{
		if (visit & (1 << i))
			continue;

		if (capacity < arr[i])
		{
			ret = max(ret, TSP(visit, idx + 1, C) );
		}
		else
		{
			ret = max(ret, TSP(visit | (1 << i), idx, capacity - arr[i]) + 1);
		}
	}

	return ret;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	memset(dp, -1, sizeof(dp));

	cin >> N >> M >> C;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	cout << TSP(0,0,C);
	

	return 0;
}