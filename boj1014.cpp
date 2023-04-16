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

int cache[11][1 << 10];
int board[11][11];
int testcase;
vector<string> pos[11];
vector<int> arr;
int N, M;

void dfs(int idx, int fin)
{
	if (idx == fin)
	{
		string tmp;
		for (auto i : arr)
			tmp += to_string(i);
		pos[idx].push_back(tmp);
		return;
	}

	arr.push_back(0);
	dfs(idx + 1, fin);
	arr.pop_back();

	if (arr.size() > 0 && arr.back() == 1)
		return;

	arr.push_back(1);
	dfs(idx + 1, fin);
	arr.pop_back();
}

int dp(int idx, int bits)
{
	if (idx == N)
		return 0;

	int& ret = cache[idx][bits];

	if (ret != -1)
		return ret;

	int ans = 0;
	for (auto i : pos[M])
	{
		int curbit = 0;
		int count = 0;

		for (int j = 0; j < M; j++)
		{
			if (i[j] == '0')
				continue;

			if (board[idx][j])
				continue;

			if (0 < j && bits & (1 << j - 1))
				continue;

			if (j < M && bits & (1 << j + 1))
				continue;

			count++;
			curbit += (1 << j);
		}

		ans = max(ans, dp(idx + 1, curbit) + count);
	}

	return ret = ans;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> testcase;

	for (int i = 1; i <= 10; i++)
		dfs(0, i);

	while (testcase--)
	{
		//initialize
		memset(cache, -1, sizeof(cache));
		memset(board, 0, sizeof(board));

		cin >> N >> M;

		for (int i = 0; i < N; i++)
		{
			string tmp;
			cin >> tmp;
			for (int j = 0; j < M; j++)
			{
				if (tmp[j] == '.')
					board[i][j] = 0;
				else
					board[i][j] = 1;
			}
		}

		cout << dp(0, 0) << "\n";
	}
	

	return 0;
}

