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

vector<pair<int, int>> v;
int dp[10001] = {
    0,
};
vector<int> recF;
vector<int> recB;

int main()
{
   int n;
   scanf("%d", &n);

   vector<int> idx(n + 1);
   vector<int> rev(n + 1);
   for (int i = 0; i < n; i++)
   {
      int val;
      scanf("%d", &val);

      idx[val] = i;
      rev[i] = val;
   }

   vector<int> arr(n);
   for (int i = 0; i < n; i++)
   {
      int val;
      scanf("%d", &val);

      arr[i] = idx[val];
   }

   vector<int> lis(n, INF);
   vector<pair<int, int>> trace;

   int plis = 0;

   lis[0] = arr[0];
   trace.push_back({0, arr[0]});

   for (int i = 1; i < n; i++)
   {
      auto it = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
      lis[it] = arr[i];
      trace.push_back({it, arr[i]});
   }

   int len = lis.size();
   for (int i = 0; i < len; i++)
      if (lis[i] != INF)
         plis++;

   plis--;

   len = trace.size();

   vector<int> ansIdx;
   for (int i = len - 1; i >= 0; i--)
   {
      if (trace[i].first != plis)
         continue;

      ansIdx.push_back(trace[i].second);
      plis--;
   }

   vector<int> ans;

   len = ansIdx.size();
   for (int i = 0; i < len; i++)
      ans.push_back(rev[ansIdx[i]]);

   sort(ans.begin(), ans.end());

   printf("%d\n", ans.size());
   for (auto i : ans)
      printf("%d ", i);

   return 0;
}