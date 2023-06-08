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
	double x, y;

	bool operator < (const Point& a)
	{
		if (y == a.y)
			return x < a.x;
		else
			return y < a.y;
	}
};

double ccw(const Point& a, const Point& b, const Point& c)
{
	return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

double dist(Point a, Point b)
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

vector<int> arr[10];
vector<vector<ll>> graph(10, vector<ll>(10));
vector<vector<ll>> cache(10, vector<ll>(10));
const int MOD = 1000000007;

void makeNode()
{
	arr[1].push_back(2);
	arr[1].push_back(3);
	arr[2].push_back(1);
	arr[2].push_back(3);
	arr[2].push_back(4);
	arr[3].push_back(1);
	arr[3].push_back(2);
	arr[3].push_back(4);
	arr[3].push_back(5);
	arr[4].push_back(2);
	arr[4].push_back(3);
	arr[4].push_back(5);
	arr[4].push_back(6);
	arr[5].push_back(3);
	arr[5].push_back(4);
	arr[5].push_back(6);
	arr[5].push_back(7);
	arr[6].push_back(4);
	arr[6].push_back(5);
	arr[6].push_back(8);
	arr[7].push_back(5);
	arr[7].push_back(8);
	arr[8].push_back(6);
	arr[8].push_back(7);

	for (int i = 1; i <= 9; i++)
	{
		for (auto j : arr[i])
		{
			graph[i][j] = 1;
		}
	}
}

vector<vector<ll>> multiply(const vector<vector<ll>>& a, const vector<vector<ll>>& b) 
{
	vector<vector<ll>> ret(10, vector<ll>(10));

	for (int i = 1; i <= 8; i++) 
	{
		for (int j = 1; j <= 8; j++) 
		{
			ll elem = 0;
			for (int k = 1; k <= 8; k++) 
			{
				elem += (a[i][k] * b[k][j]) % MOD;
			}
			ret[i][j] = elem % MOD;
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	makeNode();
	ll D;

	cin >> D;

	for (int i = 0; i < 9; i++)
	{
		cache[i][i] = 1;
	}

	while (true)
	{
		if (D == 0)
			break;

		if (D % 2 == 1)
		{
			cache = multiply(cache, graph);
			D -= 1;
		}
		graph = multiply(graph, graph);
		D /= 2;
	}

	cout << cache[1][1];

	return 0;
}