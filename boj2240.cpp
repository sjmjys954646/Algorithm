// freopen("input.txt", "r", stdin);
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <cstring>
#include <list>
#include <set>
#include <string.h>
#include <map>
#include <limits.h>
#include <stdlib.h>
#include <typeinfo>
#include <bitset>

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

int cache[1002][3][32];
int T, W;
vi v;

int dp(int second, int pos, int move)
{
	if (second == T)
		return 0;

	int& ret = cache[second][pos][move];

	if (ret != -1)
		return ret;

	int add = 0;
	if (v[second] == pos)
		add++;


	int nextmove;
	if (pos == 1)
		nextmove = 2;
	else
		nextmove = 1;

	if (add)
	{
		if (move < W)
			ret = max(dp(second + 1, pos, move) + 1, dp(second + 1, nextmove, move + 1));
		else
			ret = dp(second + 1, pos, move) + 1;
	}
	else
	{
		if (move < W)
			ret = max(dp(second + 1, pos, move), dp(second + 1, nextmove, move + 1) + 1);
		else
			ret = dp(second + 1, pos, move);

	}

	return ret;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(cache, -1, sizeof(cache));

	cin >> T >> W;

	rep(i, T)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	cout << dp(0, 1, 0);


	return 0;
}