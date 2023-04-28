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
typedef vector<int> vi;

const int INF = 987654321;

int N;

long long arr[101][101];
long long cache[101][101];

long long dp(int y, int x)
{

    if (y == N - 1 && x == N - 1)
        return 1;

    if (y  >= N || x >= N)
        return 0;

    if (arr[y][x] == 0)
        return 0;

    long long& ret  = cache[y][x];

    if (ret != -1)
        return ret;

    long long cur = arr[y][x];

    return ret = dp(y + cur, x)+dp(y, x + cur);
}


int main()
{
    memset(cache, -1, sizeof(cache));

    scanf("%d", &N);

    rep(i, N)
    {
        rep(j, N)
        {
            cin >> arr[i][j];
        }
    }

    cout<<dp(0, 0);

    return 0;
}