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

int x, y;
int N;
vi ycut; //세로로자름
vi xcut; // 가로로자름

int main()
{

   int a, b;
   int xcutF = 0, xcutB = 0, ycutF = 0, ycutB = 0;

   scanf("%d %d", &x, &y);

   scanf("%d", &N);

   rep(i, N)
   {
      scanf("%d %d", &a, &b);
      if (a == 0)
         xcut.pb(b);
      else
         ycut.pb(b);
   }

   xcut.pb(0);
   xcut.pb(y);
   ycut.pb(0);
   ycut.pb(x);

   sort(xcut.begin(), xcut.end());
   sort(ycut.begin(), ycut.end());

   vi sq;

   for (int i = 0; i < xcut.size() - 1; i++)
   {
      int column = xcut[i + 1] - xcut[i];
      for (int j = 0; j < ycut.size() - 1; j++)
      {
         int row = ycut[j + 1] - ycut[j];
         sq.pb(row * column);
      }
   }

   sort(sq.begin(), sq.end());

   printf("%d", sq[sq.size() - 1]);

   return 0;
}