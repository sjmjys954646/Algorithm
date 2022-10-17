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
int l[2002];
int r[2002];
int cache[2002][2002] = {
    0,
};
// 왼쪽 카드가 x장 오른쪽 카드가 y장 남았을때 최고 점수

int dp(int x, int y)
{
   if (x == N || y == N)
      return 0;

   int &ret = cache[x][y];

   if (ret != -1)
      return ret;

   ret = max(dp(x + 1, y), dp(x + 1, y + 1));

   if (l[x] > r[y])
      ret = max(ret, dp(x, y + 1) + r[y]);

   return ret;
}

int main()
{
   memset(cache, -1, sizeof(cache));

   scanf("%d", &N);

   for (int i = 0; i < N; i++)
   {
      scanf("%d", &l[i]);
   }
   for (int i = 0; i < N; i++)
   {
      scanf("%d", &r[i]);
   }

   int ans = dp(0, 0);

   printf("%d", ans);

   return 0;
}