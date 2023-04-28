#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <string>
#include<string.h> 

using namespace std;

int cache[51][51][502];
int w[51][51];
int t[51][51];
int N, M, T;

int main()
{
	memset(cache, -1, sizeof(cache));

	cin >> N >> M >> T;

	for(int i = 1;i<=N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> w[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> t[i][j];
		}
	}

	cache[1][1][0] = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (i == 1 && j == 1)
				continue;

			for (int k = 1; k <= T; k++)
			{
				int cur = cache[i][j][k];

				int a = cache[i][j - 1][k - 1];
				int b = cache[i-1][j][k - 1];
				int c = cache[i - 1][j-1][k - 1];
				int d= -1, e = -1, f = -1;

				if (k - 1 - t[i][j] >= 0 && cache[i][j - 1][k - 1 - t[i][j]] != -1)
					d = cache[i][j - 1][k - 1 - t[i][j]] + w[i][j];

				if (k - 1 - t[i][j] >= 0 && cache[i-1][j][k - 1 - t[i][j]] != -1)
					e = cache[i-1][j][k - 1 - t[i][j]] + w[i][j];

				if (k - 1 - t[i][j] >= 0 && cache[i-1][j - 1][k - 1 - t[i][j]] != -1)
					f = cache[i-1][j - 1][k - 1 - t[i][j]] + w[i][j];

				cache[i][j][k] = max({ a,b,c,d,e,f });

			}
		}
	}
	
	int ans = -1;

	for (int i = 0; i <= T; i++)
	{
		ans = max(ans, cache[N][M][i]);
	}
	cout << ans;

	return 0;
}