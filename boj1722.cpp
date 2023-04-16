#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include  <vector>
#include <utility>
#include <algorithm>

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

int N;
int order;
ll a;
int tmp;
vi v;
int visited[22];

vector<ll> fac;
vi ans;
ll aans = 1;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	fac.resize(22);
	fac[0] = 1;
	fac[1] = 1;
	for (int i = 2; i <= 20; i++)
	{
		fac[i] = i * fac[i - 1];
	}

	cin >> N;

	cin >> order;

	if (order == 1)
	{
		cin >> a;

		for (int i = 1; i <= N; i++)
		{
			int index = 1;
			while (true)
			{
				if (visited[index])
				{
					index++;
					continue;
				}

				if (fac[N - i] < a)
				{
					index++;
					a -= fac[N - i];
					continue;
				}

				ans.push_back(index);
				visited[index] = 1;
				break;
			}
		}

		for (auto i : ans)
			cout << i << " ";
	}
	else if (order == 2)
	{
		rep(i, N)
		{
			cin >> tmp;
			v.push_back(tmp);
		}

		for (int i = 1; i <= N; i++)
		{
			int cur = v[i-1];
			int index = 1;
			int pos = 0;
			while (true)
			{
				if (visited[index])
				{
					index++;
					continue;
				}

				if (index == cur)
				{
					aans += fac[N - i]  * pos;
					visited[index] = 1;
					break;
				}

				index++;
				pos++;
			}
		}
		cout << aans;
	}


	return 0;
}