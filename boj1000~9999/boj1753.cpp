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

vector<pair<int, int>> graph[20002];
int V, E;
int start;
int visited[20002];

int main()
{
   int a, b, c;
   scanf("%d %d", &V, &E);

   scanf("%d", &start);

   for (int i = 0; i < E; i++)
   {
      scanf("%d %d %d", &a, &b, &c);
      graph[a].push_back({b, c});
   }

   for (int i = 0; i <= V; i++)
      visited[i] = INF;

   priority_queue<pair<int, int>> pq;
   visited[start] = 0;
   pq.push({0, start});

   while (!pq.empty())
   {
      int cost = -pq.top().F;
      int cur = pq.top().S;

      pq.pop();

      if (cost > visited[cur])
         continue;

      for (int i = 0; i < graph[cur].size(); i++)
      {
         int next = graph[cur][i].F;
         int nextCost = graph[cur][i].S + cost;

         if (nextCost < visited[next])
         {
            pq.push({-nextCost, next});
            visited[next] = nextCost;
         }
      }
   }

   for (int i = 1; i <= V; i++)
   {
      if (visited[i] == INF)
         cout << "INF\n";
      else
         cout << visited[i] << "\n";
   }

   return 0;
}