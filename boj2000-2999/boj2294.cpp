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

int coin[101];
int dp[10001];

int main()
{
   int n, k;
   cin >> n >> k;

   for (int i = 0; i < n; i++)
      cin >> coin[i];

   for (int i = 0; i <= k; ++i)
      dp[i] = INF;

   dp[0] = 0;

   for (int i = 0; i < n; i++)
   {
      for (int j = coin[i]; j <= k; j++)
      {
         dp[j] = min(dp[j], dp[j - coin[i]] + 1);
      }
   }


   if (dp[k] == INF)
      cout << -1;
   else
      cout << dp[k];

   return 0;
}