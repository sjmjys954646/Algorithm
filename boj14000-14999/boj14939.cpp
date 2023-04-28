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

//
//ll arr[1000002];
//ll tree[4 * 1000002];
//ll N, M, K;
//ll order;
//ll a, b, c, d;
//
//ll init(ll start, ll end, ll node)
//{
//	if (start == end)
//		return tree[node] = arr[start];
//
//	ll mid = (start + end) / 2;
//
//	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
//}
//
//ll query(ll start, ll end, ll node, ll left, ll right)
//{
//	if (left > end || right < start)
//		return 0;
//
//	if (left <= start && end <= right)
//		return tree[node];
//
//	ll mid = (start + end) / 2;
//
//	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
//}
//
//ll update(ll start, ll end, ll node, ll index, ll diff)
//{
//	if (index < start || end < index)
//		return tree[node];
//
//	if (start == end)
//		return tree[node] = diff;;
//
//	ll mid = (start + end) / 2;
//
//	return tree[node] = update(start, mid, node * 2, index, diff) + update(mid + 1, end, node * 2 + 1, index, diff);
//}

int arr[12][12];
int board[12][12];
string tmp;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

void click(int curY, int curX)
{
	board[curY][curX] = !board[curY][curX];
	for (int i = 0; i < 4; i++)
	{
		int nY = curY + dy[i];
		int nX = curX + dx[i];

		if (nY < 0 || nX < 0 || nY >= 10 || nX >= 10)
			continue;

		board[nY][nX] = !board[nY][nX];
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	for (int i = 0; i < 10; i++)
	{
		cin >> tmp;
		for (int j = 0; j < 10; j++)
		{
			if (tmp[j] == '#')
				arr[i][j] = 0;
			else
				arr[i][j] = 1;
		}
	}

	int ans = INF;
	for (int bit = 0; bit < 1024; bit++)
	{
		int num = 0;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				board[i][j] = arr[i][j];
			}
		}

		for (int i = 0; i < 10; i++)
		{
			if (bit & 1 << i)
			{
				click(0, i);
				num++;
			}
		}

		for (int i = 1; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (board[i - 1][j] == 1)
				{
					click(i, j);
					num++;
				}
			}
		}

		bool pos = true;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (board[i][j] == 1)
					pos = false;
			}
		}

		if (pos)
			ans = min(ans, num);
	}

	if (ans == INF)
		cout << -1;
	else
		cout << ans;

	return 0;
}