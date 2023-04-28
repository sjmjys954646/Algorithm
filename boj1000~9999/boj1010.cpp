#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

int cache[32][32];

int dp(int a, int b)
{
	int& ret = cache[a][b];
	if (ret != -1)
		return ret;

	int tot = 0;
	for (int i = 1; i <= b-a+1; i++)
	{
		tot += dp(a - 1, b - i);
	}
	return ret = tot;
}	


int main()
{
	memset(cache, -1, sizeof(cache));

	int T;

	cin >> T;


	for (int i = 0; i < 32; i++)
	{
		cache[0][i] = 1;
	}

	while (T--)
	{
		int a, b;
		cin >> a >> b;
		cout << dp(a, b)<<"\n";
	}


	return 0;
}