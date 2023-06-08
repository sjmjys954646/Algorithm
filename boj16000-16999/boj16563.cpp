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

//ll arr[100002];
//ll tree[4 * 100002];
//ll N, M, K;
//ll order;
//ll a, b, c, d;
//
//ll init(ll start, ll end, ll node)
//{
//	if (start == end)
//		return tree[node] = arr[start] - arr[start - 1];
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
//		return tree[node] += diff;;
//
//	ll mid = (start + end) / 2;
//
//	return tree[node] = update(start, mid, node * 2, index, diff) + update(mid + 1, end, node * 2 + 1, index, diff);
//}


//int c[202][402];
//int f[202][402];
//int d[202];
//int a[1002];
//int b[1002];
//vector<int> arr[1002];
//int N, M;
//int cap;
//
//int maxFlow(int source, int sink)
//{
//	memset(f, 0, sizeof(f));
//	int ans = 0;
//
//	while (1)
//	{
//		memset(d, -1, sizeof(d));
//		queue<int> q;
//		q.push(source);
//
//		while (!q.empty())
//		{
//			int cur = q.front();
//			q.pop();
//
//			for (int i = 0; i < arr[cur].size(); i++)
//			{
//				int next = arr[cur][i];
//				if (c[cur][next] - f[cur][next] > 0 && d[next] == -1)
//				{
//					d[next] = cur;
//					q.push(next);
//				}
//			}
//		}
//
//		if (d[sink] == -1)
//			break;
//
//		int flow = INF;
//		for (int i = sink; i != source; i = d[i])
//		{
//			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
//		}
//
//		for (int i = sink; i != source; i = d[i])
//		{
//			f[d[i]][i] += flow;
//			f[i][d[i]] -= flow;
//		}
//
//		ans += flow;
//
//	}
//
//	return ans;
//}
//
//int dfs(int x)
//{
//	d[x] = 1;
//	for (int i = 0; i < arr[x].size(); i++)
//	{
//		int p = arr[x][i];
//
//		if (b[p] == -1 || !d[b[p]] && dfs(b[p]))
//		{
//			a[x] = p;
//			b[p] = x;
//			return 1;
//		}
//
//	}
//	return 0;
//}

int N;
int primeNumber[5000005];
vi pp;
int testcase;

void Eratos()
{
	for (int i = 2; i <= N; i++)
	{
		primeNumber[i] = i;
	}

	for (int i = 2; i <= sqrt(N); i++)
	{
		if (primeNumber[i] == 0)
			continue;

		for (int j = i * i; j <= N; j += i)
			primeNumber[j] = 0;
	}

	for (int i = 2; i <= N; i++)
	{
		if (primeNumber[i] != 0)
			pp.push_back(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	N = 5000000;

	Eratos();

	cin >> testcase;

	while (testcase--)
	{
		cin >> N;

		while (true)
		{
			if (primeNumber[N] != 0)
			{
				cout << N;
				break;
			}

			for (int i = 0; i < pp.size(); i++)
			{
				if (N % pp[i] == 0)
				{
					cout << pp[i] << " ";
					N /= pp[i];
					break;
				}
			}
		}

		
		cout << "\n";
	}

	
	

	return 0;
}