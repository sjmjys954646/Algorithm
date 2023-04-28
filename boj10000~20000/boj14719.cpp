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


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	int H, W;
	int tmp;
	int curmax = 0;
	int ans = 0;

	cin >> H >> W;

	stack<int> s;

	for (int i = 0; i < W; i++)
	{
		cin >> tmp;

		if (s.empty() && tmp == 0)
			continue;

		if (s.empty())
		{
			s.push(tmp);
			curmax = tmp;
			continue;
		}

		if (tmp >= curmax)
		{
			while (!s.empty())
			{
				int p = s.top();
				s.pop();
				ans += (curmax - p);
			}
			curmax = tmp;
			s.push(tmp);
		}
		else
		{
			s.push(tmp);
		}
	}

	if (!s.empty())
	{
		curmax = s.top();
		s.pop();

		while (!s.empty())
		{
			int p = s.top();
			s.pop();

			if (p >= curmax)
			{
				curmax = p;
			}
			else
			{
				ans += (curmax - p);
			}
		}
	}

	cout << ans;

	return 0;
}