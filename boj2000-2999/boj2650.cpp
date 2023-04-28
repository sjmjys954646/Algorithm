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

//https://degurii.tistory.com/123

const int INF = 987654321;

int d[5] = {0, 0, 2, 3, 1};
vector<pii> v;

int main()
{

   int ans = 0;
   int N, a, b;
   int x, y;

   scanf("%d", &N);
   rep(i, N / 2)
   {
      scanf("%d %d", &a, &b);
      x = d[a] * 52 + b;
      if (d[a] > 1)
         x += 52 - 2 * b;

      scanf("%d %d", &a, &b);
      y = d[a] * 52 + b;
      if (d[a] > 1)
         y += 52 - 2 * b;

      if (x > y)
         swap(x, y);

      v.pb({x, y});
   }

   int arr[52] = {
       0,
   };
   rep(i, N)
   {
      pair<int, int> p = v[i];
      rep(j, N)
      {
         auto k = v[j];
         if (p.F < k.F && k.F < p.S && p.S < k.S)
         {
            ans++;
            arr[i]++;
            arr[j]++;
         }
      }
   }
   int m = -1;
   rep(i, N)
       m = max(arr[i], m);
   printf("%d\n", ans);
   printf("%d", m);

   return 0;
}