#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <string>
#include <cmath>
#include <map>
#include <stack>
#include <sstream>
#include <string.h>
#include <queue>
using namespace std;

const int INF = 987654321;

long long cache[12][100002];
long long arr[12][100002];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	int N, M;
	long long ans = -1;

	cin >> N >> M;

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (i == 1)
				cache[j][i] = arr[j][i];
			else
			{
				for (int k = 1; k <= M; k++)
				{
					if (j == k)
						cache[j][i] = max(cache[j][i], cache[k][i - 1] + arr[j][i] / 2);
					else
						cache[j][i] = max(cache[j][i], cache[k][i - 1] + arr[j][i]);
				}
			}
		}
	}

	for (int i = 1; i <= M; i++)
		ans = max(cache[i][N], ans);

	cout << ans;

	return 0;
}
