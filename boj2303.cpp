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

int arr[1002][5];
int N;
int selected[3];
int ret[1002];

int calFirstNum()
{
   int sum = 0;
   for (auto t : selected)
   {
      sum += t;
   }
   return sum %= 10;
}

void select(int card, int num, int idx)
{
   if (num == 3)
   {
      int result = calFirstNum();
      ret[card] = max(ret[card], result);
      return;
   }

   for (int i = idx; i < 5; i++)
   {
      selected[num] = arr[card][i];
      select(card, num + 1, i + 1);
   }
}

int main()
{
   scanf("%d", &N);

   rep(i, N)
   {
      rep(j, 5)
      {
         scanf("%d", &arr[i][j]);
      }
   }

   rep(i, N)
   {
      select(i, 0, 0);
   }

   int m = -1;
   int ans = 0;
   rep(i, N)
   {
      if (m == ret[i])
         ans = i;

      if (m < ret[i])
      {
         ans = i;
         m = ret[i];
      }
   }

   cout << ans + 1;

   return 0;
}
