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
ll arr[500002];
ll tarr[500002];

ll mergesort(int start, int end)
{
   if (start == end)
      return 0;

   int mid = (start + end) / 2;

   ll ret = mergesort(start, mid) + mergesort(mid + 1, end);

   int l = start;
   int r = mid + 1;
   int idx = 0;

   while (l <= mid || r <= end)
   {
      if (l <= mid && (r > end || arr[l] <= arr[r]))
         tarr[idx++] = arr[l++];
      else
      {
         ret += (mid - l + 1) * 1LL;
         tarr[idx++] = arr[r++];
      }
   }
   for (int i = start; i <= end; i++)
      arr[i] = tarr[i - start];

   return ret;
}

int main()
{

   scanf("%d", &N);

   rep(i, N)
       scanf("%d", &arr[i]);

   ll result = mergesort(0, N - 1);

   printf("%lld", result);

   return 0;
}