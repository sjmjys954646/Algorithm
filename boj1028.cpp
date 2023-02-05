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

int N, M;
int arr[1002][1002];
int cacheA[1002][1002]; // left down
int cacheB[1002][1002]; // right down
int cacheC[1002][1002]; // left up
int cacheD[1002][1002]; // right up

int main()
{
	cin >> N >> M;

	string tmp;
	int ans = 0;

	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;
		for (int j = 1; j <= M; j++)
		{
			arr[i][j] = tmp[j - 1] - '0';
		}
	}

	for (int i = N; i >= 1; i--)
	{
		for (int j = 1; j <= M; j++)
		{
			if (arr[i][j] == 1) {
				cacheA[i][j] = cacheA[i + 1][j - 1] + 1;
				cacheB[i][j] = cacheB[i + 1][j + 1] + 1;
			}
		}		
	}
		

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (arr[i][j] == 1) {
				cacheC[i][j] = cacheC[i - 1][j - 1] + 1;
				cacheD[i][j] = cacheD[i - 1][j + 1] + 1;
			}
		}
	}


	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			int m = min(cacheA[i][j], cacheB[i][j]);
			for (int k = 1; k <= m; k++)
			{
				int t = i + 2 * (k - 1);
				if (k <= min(cacheC[t][j], cacheD[t][j]))
					ans = max(ans, k);
			}
		}
	}

	cout << ans;

	return 0;
}