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

int N, M;
int arr[8][8];
vector<pair<pii, int>> c;
int d[5] = {4, 2, 4, 4, 1};
int ans;

void update(int dir, pii c)
{
   dir = (dir % 4);

   if (dir == 0)
   {
      for (int x = c.S + 1; x < M; ++x)
      {
         if (arr[c.F][x] == 6)
            break;
         arr[c.F][x] = -1;
      }
   }
   if (dir == 1)
   {
      for (int y = c.F - 1; y >= 0; --y)
      {
         if (arr[y][c.S] == 6)
            break;
         arr[y][c.S] = -1;
      }
   }
   if (dir == 2)
   {
      for (int x = c.S - 1; x >= 0; --x)
      {
         if (arr[c.F][x] == 6)
            break;
         arr[c.F][x] = -1;
      }
   }
   if (dir == 3)
   {
      for (int y = c.F + 1; y < N; ++y)
      {
         if (arr[y][c.S] == 6)
            break;
         arr[y][c.S] = -1;
      }
   }
}

void select(int idx)
{
   if (idx == c.size())
   {
      int sum = 0;
      {
         for (int i = 0; i < N; i++)
         {
            for (int j = 0; j < M; j++)
            {
               if (arr[i][j] == 0)
                  sum++;
            }
         }
      }
      ans = min(ans, sum);
      return;
   }

   int tmp[8][8];
   int t = c[idx].S;
   for (int i = 0; i < d[t]; i++)
   {
      copy(&arr[0][0], &arr[0][0] + 8 * 8, &tmp[0][0]);
      if (t == 0)
      {
         update(i, c[idx].F);
      }
      if (t == 1)
      {
         update(i, c[idx].F);
         update(i + 2, c[idx].F);
      }
      if (t == 2)
      {
         update(i, c[idx].F);
         update(i + 1, c[idx].F);
      }
      if (t == 3)
      {
         update(i, c[idx].F);
         update(i + 1, c[idx].F);
         update(i + 2, c[idx].F);
      }
      if (t == 4)
      {
         update(i, c[idx].F);
         update(i + 1, c[idx].F);
         update(i + 2, c[idx].F);
         update(i + 3, c[idx].F);
      }
      select(idx + 1);
      copy(&tmp[0][0], &tmp[0][0] + 8 * 8, &arr[0][0]);
   }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   cin >> N >> M;

   rep(i, N)
   {
      rep(j, M)
      {
         cin >> arr[i][j];
         if (arr[i][j] != 0 && arr[i][j] != 6)
            c.pb({{i, j}, arr[i][j] - 1});
      }
   }

   ans = INF;

   select(0);

   cout << ans;

   return 0;
}