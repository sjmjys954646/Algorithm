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

int arr[104][104];

int main()
{
   int x1, x2, y1, y2;

   rep(t, 4)
   {
      scanf("%d %d %d %d", &y1, &x1, &y2, &x2);

      for (int i = y1; i < y2; i++)
      {
         for (int j = x1; j < x2; j++)
         {
            arr[i][j]++;
         }
      }
   }
   int ans = 0;
   rep(i, 103)
   {
      rep(j, 103)
      {
         if (arr[i][j])
            ans++;
      }
   }

   printf("%d", ans);

   return 0;
}