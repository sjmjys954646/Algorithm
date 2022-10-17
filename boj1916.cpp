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
vector<pair<int, int>> graph[1002];
int start, fin;
int visited[1002];

int main()
{
   scanf("%d %d", &N, &M);

   for (int i = 0; i < M; i++)
   {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      graph[a].push_back({b, c});
   }

   scanf("%d %d", &start, &fin);

   for (int i = 0; i <= N; i++)
   {
      visited[i] = INF;
   }

   visited[start] = 0;
   priority_queue<pair<int, int>> pq;
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
            visited[next] = nextCost;
            pq.push({-nextCost, next});
         }
      }
   }

   printf("%d", visited[fin]);

   return 0;
}