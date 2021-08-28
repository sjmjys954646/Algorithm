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
int cache[103];
vector<pair<int, int>> v;

/*
3
100 1
2 2
2 2
*/

int dp(int index)
{
    int &ret = cache[index];

    if (ret != -1)
        return ret;

    ret = 0;

    for (int i = index + 1; i < N; i++)
    {
        if (v[index].S >= v[i].S)
            ret = max(ret, dp(i));
    }

    return ret += 1;
}

int main()
{
    freopen("input.txt", "r", stdin);

    int a, b;

    scanf("%d", &N);

    rep(i, N)
    {
        scanf("%d %d", &a, &b);
        v.pb({max(a, b), min(a, b)});
    }

    sort(v.begin(), v.end(), greater<pair<int, int>>());

    int ans = -1;

    rep(i, N)
    {
        memset(cache, -1, sizeof(cache));
        ans = max(ans, dp(i));
    }

    printf("%d", ans);

    return 0;
}