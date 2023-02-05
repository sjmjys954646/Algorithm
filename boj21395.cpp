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

int N;
int primeNum[100005];
vi pp;

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

	for (int i = 2; i <= N; i++)
	{
		if (primeNum[i] != 0)
			pp.push_back(i);
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	N = 100004;
	Eratos();

	int T;
	cin >> T;

	while (T--)
	{
		vi v;
		int tmp;
		int n;
		int ans = INF;
		int idx = 0;

		cin >> n;

		rep(i, n)
		{
			cin >> tmp;
			v.push_back(tmp);
		}

		sort(v.begin(), v.end());

		while (true)
		{
			if (idx + n == pp.size() + 1)
				break;

			int sum = 0;
			for (int i = idx; i < idx + n; i++)
			{
				sum += abs(v[i - idx] - pp[i]);
			}
			ans = min(ans, sum);
			idx++;
		}

		cout << ans << "\n";
	}

	return 0;
}