//freopen("input.txt", "r", stdin);
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
#include <stack>
#include <cstring>
#include <list>
#include <set>
#include <string.h>
#include <map>
#include <limits.h>
#include <stdlib.h>

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
typedef vector<int> svi;

const int INF = 987654321;

ll cache[101][11][1 << 11];
ll mod = 1000000000;

int main() 
{
	int N;

	scanf("%d", &N);

	rep1(i, 9)
	{
		cache[1][i][1 << i] = 1;
	}

	for(int i = 2;i<=N;i++)
	{
		rep(j, 10)
		{
			for (int k = 1; k < 1024; k++)
			{
				if (j == 0)
				{
					cache[i][j][k | 1 << j] += cache[i - 1][j + 1][k] % mod;
				}
				else if (j == 9)
				{
					cache[i][j][k | 1 << j] += cache[i - 1][j - 1][k] % mod;
				}
				else
				{
					cache[i][j][k | 1 << j] += cache[i - 1][j - 1][k] % mod;
					cache[i][j][k | 1 << j] += cache[i - 1][j + 1][k] % mod;
				}

			}
		}
	}

	ll result = 0;

	rep(j, 10)
	{
		result = (result + cache[N][j][1023] )%mod;
	}
	printf("%lld", result);

	return 0;
}
