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

int N, M, K;
int dpW[2002][2002];
int dpB[2002][2002];
char arr[2002][2002];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 1; j <= M; j++)
		{
			arr[i][j] = tmp[j - 1];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			char p = arr[i][j];
			if (p == 'B')
			{
				if ((i + j) % 2 == 0)
					dpB[i][j] = dpB[i][j - 1] + dpB[i - 1][j] - dpB[i - 1][j - 1];
				else
					dpB[i][j] = dpB[i][j - 1] + dpB[i - 1][j] - dpB[i - 1][j - 1] + 1;

				if ((i + j) % 2 == 1)
					dpW[i][j] = dpW[i][j - 1] + dpW[i - 1][j] - dpW[i - 1][j - 1];
				else
					dpW[i][j] = dpW[i][j - 1] + dpW[i - 1][j] - dpW[i - 1][j - 1] + 1;
			}
			else if (p == 'W')
			{
				if ((i + j) % 2 == 1)
					dpB[i][j] = dpB[i][j - 1] + dpB[i - 1][j] - dpB[i - 1][j - 1];
				else
					dpB[i][j] = dpB[i][j - 1] + dpB[i - 1][j] - dpB[i - 1][j - 1] + 1;

				if ((i + j) % 2 == 0)
					dpW[i][j] = dpW[i][j - 1] + dpW[i - 1][j] - dpW[i - 1][j - 1];
				else
					dpW[i][j] = dpW[i][j - 1] + dpW[i - 1][j] - dpW[i - 1][j - 1] + 1;
			}
		}
	}
	int ans = INF;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (i - K < 0 || j - K < 0)
				continue;
			ans = min(ans, dpB[i][j] - dpB[i - K][j] - dpB[i][j - K] + dpB[i - K][j - K]);
			ans = min(ans, dpW[i][j] - dpW[i - K][j] - dpW[i][j - K] + dpW[i - K][j - K]);
		}
	}

	cout << ans;

	return 0;
}