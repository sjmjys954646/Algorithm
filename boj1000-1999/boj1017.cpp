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

int N;
int d[202];
int a[1002];
int b[1002];
vi v;
vector<int> arr[1002];
int primeNum[10000];
void Eratos()
{
	for (int i = 2; i <= N; i++)
	{
		primeNum[i] = i;
	}

	for (int i = 2; i <= sqrt(N); i++)
	{
		if (primeNum[i] == 0)
			continue;

		for (int j = i * i; j <= N; j += i)
			primeNum[j] = 0;
	}
}

int dfs(int x)
{
	d[x] = 1;
	for (int i = 0; i < arr[x].size(); i++)
	{
		int p = arr[x][i];

		if (b[p] == -1 || !d[b[p]] && dfs(b[p]))
		{
			a[x] = p;
			b[p] = x;
			return 1;
		}

	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	N = 5000;

	Eratos();

	cin >> N;

	rep(i, N)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	rep(i, N)
	{
		rep(j,N)
		{
			if (i!=j && primeNum[v[i] + v[j]] != 0)
				arr[i].push_back(j);
		}
	}

	vi ans;

	for (auto k : arr[0])
	{
		memset(a, -1, sizeof(a));
		memset(b, -1, sizeof(b));

		int cnt = 1;
		a[0] = k;
		b[k] = 0;
		for (int i = 1; i < N; i++)
		{
			if (a[i] != -1)
				continue;

			memset(d, 0, sizeof(d));
			d[0] = 1;
			if (dfs(i))
				cnt++;
		}

		if (cnt == N)
			ans.push_back(v[k]);
	}

	if (ans.empty())
		cout << -1;
	else
	{

		sort(ans.begin(), ans.end());
		for (auto i : ans)
			cout << i << " ";
	}

	

	return 0;
}