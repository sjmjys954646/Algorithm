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

int row, column;
int limit;
int miss;
vector<pii> arr;

bool cmp(pii a, pii b)
{
   return a.S < b.S;
}

bool check(int size)
{
   int cnt = 1;
   int l = arr[0].S + size - 1;
   for (int i = 1; i < miss; i++)
   {
      if (arr[i].S <= l)
         continue;
      cnt++;
      l = arr[i].S + size - 1;
      if (cnt > limit)
         return false;
   }

   return true;
}

int main()
{
   scanf("%d %d", &row, &column);
   scanf("%d", &limit);
   scanf("%d", &miss);

   arr.resize(miss);

   int maxhi = -1;
   for (int i = 0; i < miss; i++)
   {
      int a, b;
      scanf("%d %d", &a, &b);
      arr[i] = {a, b};
      if (a > maxhi)
         maxhi = a;
   }

   sort(arr.begin(), arr.end(), cmp);

   int low = maxhi;
   int high = max(row, column);
   int ans = 0;

   while (low <= high)
   {
      int mid = (low + high) / 2;

      if (check(mid))
      {
         ans = mid;
         high = mid - 1;
      }
      else
         low = mid + 1;
   }
   printf("%d", ans);

   return 0;
}