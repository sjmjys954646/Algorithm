#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#define X first
#define Y second
using namespace std;

const int INF = 987654321;

int T[22];
int P[22];
int cache[22];

int N;

int dp(int start)
{
	if (start == N+1)
		return 0;
	if (start > N + 1)
		return -INF;
	int& ret = cache[start];
	if (ret != -1)
		return ret;
	return ret = max(dp(start + 1), dp(start + T[start]) + P[start]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	memset(cache, -1, sizeof(cache));
	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> P[i];
	}
	cout << dp(1);

	
	return 0;
}