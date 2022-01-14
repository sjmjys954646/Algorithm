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
int arr[302][302];
int visited[302][302];

int dX[4] = {0, 1, 0, -1};
int dY[4] = {1, 0, -1, 0};

void bfs(int startY, int startX)
{
   queue<pii> q;
   visited[startY][startX] = 1;
   q.push({startY, startX});

   while (!q.empty())
   {
      int curY = q.front().F;
      int curX = q.front().S;
      q.pop();

      for (int i = 0; i < 4; i++)
      {
         int nY = curY + dY[i];
         int nX = curX + dX[i];

         if (nY < 0 || nX < 0 || nY >= N || nX >= M)
            continue;

         if (visited[nY][nX] == 1)
            continue;

         if (arr[nY][nX] == 0)
            continue;

         q.push({nY, nX});
         visited[nY][nX] = 1;
      }
   }
}

int splitCheck()
{
   memset(visited, 0, sizeof(visited));
   int left = 0;

   rep(i, N)
   {
      rep(j, M)
      {
         if (arr[i][j] != 0 && visited[i][j] != 1)
         {
            bfs(i, j);
            left++;
         }
      }
   }

   return left;
}

void melt()
{
   vector<pair<pair<int, int>, int>> v;
   rep(i, N)
   {
      rep(j, M)
      {
         if (arr[i][j] > 0)
         {
            int tot = 0;
            for (int t = 0; t < 4; t++)
            {
               int nY = i + dY[t];
               int nX = j + dX[t];

               if (nY < 0 || nX < 0 || nY >= N || nX >= M)
                  continue;

               if (arr[nY][nX] == 0)
                  tot++;
            }

            v.push_back({{i, j}, tot});
         }
      }
   }

   for (auto x : v)
   {
      arr[x.F.F][x.F.S] -= x.S;
      if (arr[x.F.F][x.F.S] < 0)
         arr[x.F.F][x.F.S] = 0;
   }
}

int main()
{
   scanf("%d %d", &N, &M);

   rep(i, N)
   {
      rep(j, M)
      {
         scanf("%d", &arr[i][j]);
      }
   }

   int second = 0;
   while (true)
   {
      int sC = splitCheck();
      if (sC > 1)
         break;

      if (sC == 0)
      {
         second = 0;
         break;
      }

      second++;

      int before[302][302];

      copy(&arr[0][0], &arr[0][0] + 302 * 302, &before[0][0]);

      melt();

      bool check = false;
      rep(i, N)
      {
         rep(j, M)
         {
            if (before[i][j] != arr[i][j])
            {
               check = true;
            }
         }
      }

      if (!check)
      {
         second = 0;
         break;
      }
   }

   cout << second;

   return 0;
}