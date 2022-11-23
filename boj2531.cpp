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

int arr[30002];
int N, d, k, c;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> d >> k >> c;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	int l = 0;
	int r = k - 1;
	int ans = -1;

	for (int i = 0; i < N; i++)
	{
		int cache[3002];
		memset(cache, 0, sizeof(cache));
		int sum = 0;
		if (l < r)
		{
			for (int j = l; j <= r; j++)
			{
				if (cache[arr[j]])
					continue;

				cache[arr[j]] = 1;
				sum++;
			}
		}
		else
		{
			for (int j = l; j < N; j++)
			{
				if (cache[arr[j]])
					continue;

				cache[arr[j]] = 1;
				sum++;
			}

			for (int j = 0; j <= r; j++)
			{
				if (cache[arr[j]])
					continue;

				cache[arr[j]] = 1;
				sum++;
			}
		}

		if (cache[c] != 1)
			sum++;

		ans = max(ans, sum);
		l++;
		r++;
		if (l == N)
			l = 0;
		if (r == N)
			r = 0;
	}

	cout << ans;

	return 0;
}