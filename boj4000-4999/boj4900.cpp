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

const long long INF = 9876543210;

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

map<string, int> m;
map<string, string> rev;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	m["063"] = 0;
	m["010"] = 1;
	m["093"] = 2;
	m["079"] = 3;
	m["106"] = 4;
	m["103"] = 5;
	m["119"] = 6;
	m["011"] = 7;
	m["127"] = 8;
	m["107"] = 9;

	rev["0"] = "063";
	rev["1"] = "010";
	rev["2"] = "093";
	rev["3"] = "079";
	rev["4"] = "106";
	rev["5"] = "103";
	rev["6"] = "119";
	rev["7"] = "011";
	rev["8"] = "127";
	rev["9"] = "107";

	while (true)
	{
		string order;
		cin >> order;

		if (order == "BYE")
			break;

		int cut = order.find('+');
		string add1 = order.substr(0, cut);
		string add2 = order.substr(cut + 1);
		add2.pop_back();

		int add1S = add1.size() / 3;
		int val1 = 0;
		for (int i = 0; i < add1.size(); i += 3)
		{
			val1 += m[add1.substr(i, 3)] * pow(10, add1S - i / 3 - 1);
		}

		int add2S = add2.size() / 3;
		int val2 = 0;
		for (int i = 0; i < add2.size(); i += 3)
		{
			val2 += m[add2.substr(i, 3)] * pow(10, add2S - i / 3 - 1);
		}

		int sum = val1 + val2;

		string ssum = to_string(sum);

		string ans = "";
		for (int i = 0; i < ssum.size(); i++)
		{
			string cont = "";
			ans += rev[cont + ssum[i]];
		}


		cout << add1 << "+" << add2 << "=" << ans << "\n";
	}


	return 0;
}

