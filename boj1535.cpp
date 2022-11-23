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

int L[22];
int R[22];
int cache[22][102];
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	rep1(i, N)
	{
		cin >> L[i];
	}
	
	rep1(i, N)
	{
		cin >> R[i];
	}

	memset(cache, 0, sizeof(cache));
	int ans = -1;

	rep1(i, N)
	{
		rep(j, 101)
		{
			int cost = L[i];
			int p = R[i];
			if (cost + j < 100)
			{
				cache[i][j] = max(cache[i - 1][j], cache[i - 1][j + cost] + p);
			}
			else
			{
				cache[i][j] = cache[i - 1][j];
			}
			ans = max(ans, cache[i][j]);
		}
	}


	cout << ans;

	return 0;
}