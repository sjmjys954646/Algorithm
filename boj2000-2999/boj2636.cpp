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
int arr[102][102];
vector<pair<int, int>> meltHubo;
int visited[102][102];
int dY[4] = {0, 1, 0, -1};
int dX[4] = {1, 0, -1, 0};
vi ansHubo;

void melt()
{
   int tot = 0;
   int tmparr[102][102];

   copy(&arr[0][0], &arr[0][0] + 102 * 102, &tmparr[0][0]);

   for (int i = 0; i < meltHubo.size(); i++)
   {
      int curY = meltHubo[i].F;
      int curX = meltHubo[i].S;

      if (tmparr[curY][curX] == 1)
      {
         tmparr[curY][curX] = 0;
         tot++;
      }
   }
   copy(&tmparr[0][0], &tmparr[0][0] + 102 * 102, &arr[0][0]);
   ansHubo.pb(tot);
}

void bfs()
{
   int startY = 0;
   int startX = 0;
   visited[startY][startX] = 1;
   queue<pair<int, int>> q;
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

         if (nY < 0 || nY >= y || nX < 0 || nX >= x)
            continue;
         if (visited[nY][nX] == 1)
            continue;

         if (arr[nY][nX] == 0)
         {
            visited[nY][nX] = 1;
            q.push({nY, nX});
         }
         else if (arr[nY][nX] == 1)
         {
            meltHubo.pb({nY, nX});
         }
      }
   }
}

bool meltCheck()
{
   bool ok = false;

   rep(i, y)
   {
      rep(j, x)
      {
         if (arr[i][j] == 1)
         {
            ok = true;
            break;
         }
      }
   }
   return ok;
}

int main()
{

   scanf("%d %d", &y, &x);

   rep(i, y)
       rep(j, x)
           scanf("%d", &arr[i][j]);

   while (true)
   {
      if (!meltCheck())
         break;

      memset(visited, 0, sizeof(visited));

      bfs();
      melt();
   }

   printf("%d\n", ansHubo.size());
   printf("%d", ansHubo.back());

   return 0;
}