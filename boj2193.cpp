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

long long cache[100];
int num;

long long dp(int N)
{
	long long& ret = cache[N];

	if (ret != -1)
		return ret;

	long long p=0;
	for (int i = 0; i < N - 1; i++)
	{
		p += dp(i);
	}
	p += 1;
	return ret = p;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(cache, -1, sizeof(cache));

	cin >> num;

	cache[0] = 1;
	cache[1] = 1;

	cout << dp(num - 1);

	return 0;
}