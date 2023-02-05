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
using namespace std;

const long long INF = 987654321;

long long arr[21][21];
int N;
long long dp[1 << 21][21];

long long TSP(int visit, int start)
{
	if (visit == (1 << N) - 1)
		return 0;

	long long& ret = dp[visit][start];

	if (ret >= 0)
		return ret;

	ret = INF;

	for (int i = 1; i <= N; i++)
	{
		if (visit & (1 << (i - 1)))
			continue;

		ret = min(ret,TSP(visit + (1 << (i - 1)), start + 1) + arr[start][i]) ;
	}

	return ret;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	
	memset(dp, -1, sizeof(dp));

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << TSP(0, 1);

	return 0;
}
