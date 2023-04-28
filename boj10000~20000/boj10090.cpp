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

ll N, M, K;
ll seg[4000002];

ll update(ll pos, ll val, ll node, ll x, ll y)
{
   if (pos < x || y < pos)
      return seg[node];
   if (x == y)
      return seg[node] = seg[node] += 1;

   ll mid = (x + y) / 2;

   return seg[node] = update(pos, val, node * 2, x, mid) + update(pos, val, node * 2 + 1, mid + 1, y);
}

ll query(ll lo, ll hi, ll node, ll x, ll y)
{
   if (y < lo || hi < x)
      return 0;
   if (lo <= x && y <= hi)
      return seg[node];

   ll mid = (x + y) / 2;

   return query(lo, hi, node * 2, x, mid) + query(lo, hi, node * 2 + 1, mid + 1, y);
}

int main()
{

   ll tmp, a, b, c;
   tmp = 0;
   scanf("%lld", &N);

   rep(i, N)
   {
      scanf("%lld", &a);
      tmp += (ll)(a - 1 - query(1, a - 1, 1, 1, N));
      update(a, 0, 1, 1, N);
   }

   printf("%lld", tmp);

   return 0;
}