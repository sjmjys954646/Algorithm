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

struct Point
{
	ll x, y;

	bool operator<(const Point &a)
	{
		if (y == a.y)
			return x < a.x;
		else
			return y < a.y;
	}
};

ll ccw(const Point &a, const Point &b, const Point &c)
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

int testcase;
int N, M, K;
int a, b, c;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> testcase;

	// cout << 'a' - 'A';
	// 32

	while (testcase--)
	{
		int ans = 0;
		cin >> N >> K;
		string tmp;

		cin >> tmp;

		int arr[82] = {
			0,
		};
		for (int i = 0; i < N; i++)
		{
			arr[tmp[i] - 'A']++;
		}

		for (int i = 0; i < 81; i++)
		{
			if (arr[i] == 0)
				arr[i] = -1;
		}

		for (int i = 0; i < 26; i++)
		{
			if (arr[i] == -1 || arr[i + 32] == -1)
				continue;

			int p = min(arr[i], arr[i + 32]);
			ans += p;
			arr[i] -= p;
			arr[i + 32] -= p;
		}

		for (int i = 0; i < 80; i++)
		{
			if (K == 0)
				break;

			if (arr[i] == -1)
				continue;

			if (arr[i] >= 2)
			{
				int p = min(arr[i] / 2, K);
				ans += p;
				K -= p;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}