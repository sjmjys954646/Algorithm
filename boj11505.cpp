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
ll seg[4000002];

ll update(ll pos, ll val, ll node, ll x, ll y)
{
   if (pos < x || y < pos)
      return seg[node];
   if (x == y)
      return seg[node] = val;

   ll mid = (x + y) / 2;

   return seg[node] = update(pos, val, node * 2, x, mid) * update(pos, val, node * 2 + 1, mid + 1, y) % t;
}

ll query(ll lo, ll hi, ll node, ll x, ll y)
{
   if (y < lo || hi < x)
      return 1;
   if (lo <= x && y <= hi)
      return seg[node];

   ll mid = (x + y) / 2;

   return query(lo, hi, node * 2, x, mid) * query(lo, hi, node * 2 + 1, mid + 1, y) % t;
}

int main()
{
   ll tmp, a, b, c;

   scanf("%lld %lld %lld", &N, &M, &K);

   for (int i = 1; i <= N; i++)
   {
      scanf("%lld", &tmp);
      update(i, tmp, 1, 1, N);
   }

   rep(i, M + K)
   {
      scanf("%lld %lld %lld", &a, &b, &c);
      if (a == 1)
         update(b, c, 1, 1, N);
      else
         printf("%lld\n", query(b, c, 1, 1, N));
   }

   return 0;
}