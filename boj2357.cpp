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

const ll t = 1000000007;
const int INF = 987654321;

ll N, M, K;
ll Sseg[4000002];
ll Bseg[4000002];

ll Bupdate(ll pos, ll val, ll node, ll x, ll y)
{
    if (pos < x || y < pos)
        return Bseg[node];
    if (x == y)
        return Bseg[node] = val;

    ll mid = (x + y) / 2;

    return Bseg[node] = max(Bupdate(pos, val, node * 2, x, mid), Bupdate(pos, val, node * 2 + 1, mid + 1, y));
}

ll Bquery(ll lo, ll hi, ll node, ll x, ll y)
{
    if (y < lo || hi < x)
        return -1;
    if (lo <= x && y <= hi)
        return Bseg[node];

    ll mid = (x + y) / 2;

    return max(Bquery(lo, hi, node * 2, x, mid), Bquery(lo, hi, node * 2 + 1, mid + 1, y));
}

ll Supdate(ll pos, ll val, ll node, ll x, ll y)
{
    if (pos < x || y < pos)
        return Sseg[node];
    if (x == y)
        return Sseg[node] = val;

    ll mid = (x + y) / 2;

    return Sseg[node] = min(Supdate(pos, val, node * 2, x, mid), Supdate(pos, val, node * 2 + 1, mid + 1, y));
}

ll Squery(ll lo, ll hi, ll node, ll x, ll y)
{
    if (y < lo || hi < x)
        return 1000000001;
    if (lo <= x && y <= hi)
        return Sseg[node];

    ll mid = (x + y) / 2;

    return min(Squery(lo, hi, node * 2, x, mid), Squery(lo, hi, node * 2 + 1, mid + 1, y));
}

int main()
{
    freopen("input.txt", "r", stdin);
    ll tmp, a, b, c;

    scanf("%lld %lld", &N, &M);

    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &tmp);
        Supdate(i, tmp, 1, 1, N);
        Bupdate(i, tmp, 1, 1, N);
    }

    rep(i, M)
    {
        scanf("%lld %lld", &a, &b);
        printf("%lld %lld\n", Squery(a, b, 1, 1, N), Bquery(a, b, 1, 1, N));
    }

    return 0;
}