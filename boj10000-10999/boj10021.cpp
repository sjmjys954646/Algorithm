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

int N, C;
const int INF = 987654321;
vector<pii> arr;
vector<pii> graph[3000];
bool visit[3000];
bool check;

int main()
{

   scanf("%d %d", &N, &C);

   rep(i, N)
   {
      int a, b;
      scanf("%d %d", &a, &b);
      arr.push_back({a, b});
   }

   rep(i, N)
   {
      for (int j = i + 1; j < N; j++)
      {
         int t = (arr[i].F - arr[j].F) * (arr[i].F - arr[j].F) + (arr[i].S - arr[j].S) * (arr[i].S - arr[j].S);
         graph[i].pb({j, t});
         graph[j].pb({i, t});
      }
   }

   priority_queue<pii> pq;
   int ans = 0;

   for (int i = 0; i < graph[0].size(); i++)
   {
      int next = graph[0][i].F;
      int cost = graph[0][i].S;
      if (cost >= C)
         pq.push({-cost, next});
   }
   visit[0] = true;

   while (!pq.empty())
   {
      int cost = -pq.top().F;
      int cur = pq.top().S;
      pq.pop();

      if (visit[cur] == false)
      {
         visit[cur] = true;
         ans += cost;

         for (int i = 0; i < graph[cur].size(); i++)
         {
            int next = graph[cur][i].F;
            int ncost = graph[cur][i].S;
            if (visit[next] == false && ncost >= C)
               pq.push({-ncost, next});
         }
      }
   }

   rep(i, N)
   {
      if (!visit[i])
         check = true;
   }

   if (check)
      cout << -1;
   else
      cout << ans;

   return 0;
}