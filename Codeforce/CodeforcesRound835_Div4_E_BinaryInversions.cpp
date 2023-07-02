// freopen("input.txt", "r", stdin);
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

int testcase;
int N;
int tmp;
int prefix[200002] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> testcase;


	while (testcase--)
	{
		vi v;
		int frontzero = -1;
		int backone = -1;
		ll ans = 0;
		cin >> N;

		rep(i, N)
		{
			cin >> tmp;
			v.push_back(tmp);
			if (frontzero == -1 && tmp == 0)
				frontzero = i;
			if (tmp == 1)
				backone = max(backone, i);
		}
		memset(prefix, 0, sizeof(prefix));
		ll cur = 0;
		ll sum = 0;
		for(int i = N-1;i>=0;i--)
		{
			if (v[i] == 0)
			{
				cur += 1;
				prefix[i] = cur;
			}		
			else
			{
				prefix[i] = cur;
			}
		}

		/*for (int i = 0; i < N; i++)
			cout << prefix[i] << " ";
		cout << "\n";*/

		for (int i = 0; i < N; i++)
		{
			if (v[i] == 1)
			{
				sum += prefix[i];
			}
		}
		ans = max(ans, sum);
		//cout << sum << "\n";

		if (frontzero != -1)
		{
			memset(prefix, 0, sizeof(prefix));
			v[frontzero] = 1;
			cur = 0;
			sum = 0;
			for (int i = N - 1; i >= 0; i--)
			{
				if (v[i] == 0)
				{
					cur += 1;
					prefix[i] = cur;
				}
				else
				{
					prefix[i] = cur;
				}
			}
			for (int i = 0; i < N; i++)
			{
				if (v[i] == 1)
				{
					sum += prefix[i];
				}
			}
			ans = max(ans, sum);
			v[frontzero] = 0;
			//cout << sum << "\n";
		}

		if (backone != -1)
		{
			memset(prefix, 0, sizeof(prefix));
			v[backone] = 0;
			cur = 0;
			sum = 0;
			for (int i = N - 1; i >= 0; i--)
			{
				if (v[i] == 0)
				{
					cur += 1;
					prefix[i] = cur;
				}
				else
				{
					prefix[i] = cur;
				}
			}
			for (int i = 0; i < N; i++)
			{
				if (v[i] == 1)
				{
					sum += prefix[i];
				}
			}
			ans = max(ans, sum);
			//cout << sum << "\n";

		}
		cout << ans << "\n";
	}
	

	return 0;
}