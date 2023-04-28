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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int maxi = -1;

	cin >> N;

	priority_queue<int> pq;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}

	int a = 0;
	int b = 0;
	int ans = 0;

	while (true)
	{
		if (a == 0 && b == 0 && pq.empty())
			break;
		if (a == 0 && !pq.empty())
		{
			a = pq.top();
			pq.pop();
		}
		if (b == 0 && !pq.empty())
		{
			b = pq.top();
			pq.pop();
		}
		int t = 0;
		if (a != 0 && b != 0)
		{
			t = min(a, b);
			a -= t;
			b -= t;
			pq.push(max(a, b));
			a = 0;
			b = 0;
		}
		else if (a == 0 && b != 0)
		{
			t = b;
			b -= t;
		}
		else if (a != 0 && b == 0)
		{
			t = a;
			a -= t;
		}

		ans += t;


	}

	if (ans > 1440)
		cout << -1;
	else
		cout << ans;


	return 0;
}