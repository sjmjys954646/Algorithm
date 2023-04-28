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

int V, E;
vector<int> arr[100002];
bool finished[100002]; // scc가 만들어됬는지
stack<int> S;
int num = 0;
int sccN = 0;
int visited[100002];     // 방문 번호
vector<int> scc[100002]; //scc 목록
int sccM[100002];        // 어느 scc group에 속해있는지
int indegree[100002];

int dfs(int start)
{
   visited[start] = ++num;
   S.push(start);
   int ret = visited[start];

   for (int next : arr[start])
   {
      if (!visited[next])
         ret = min(ret, dfs(next));
      else if (!finished[next])
         ret = min(ret, visited[next]);
   }

   if (ret == visited[start])
   {
      sccN++;
      while (true)
      {
         int tmp = S.top();
         S.pop();
         sccM[tmp] = sccN;
         finished[tmp] = true;
         if (tmp == start)
            break;
      }
   }

   return ret;
}

int main()
{

   int testcase;

   scanf("%d", &testcase);

   while (testcase--)
   {
      memset(finished, 0, sizeof(finished));
      memset(visited, 0, sizeof(visited));
      memset(indegree, 0, sizeof(indegree));
      sccN = 0;
      num = 0;
      for (int i = 0; i < 100002; i++)
      {
         scc[i].clear();
         arr[i].clear();
      }

      int A, B;

      scanf("%d %d", &V, &E);

      rep(i, E)
      {
         scanf("%d %d", &A, &B);
         arr[A].pb(B);
      }

      rep(i, V)
      {
         if (!visited[i])
            dfs(i);
      }

      rep(i, V)
      {
         for (int j = 0; j < arr[i].size(); j++)
         {
            int nxt = arr[i][j];
            if (sccM[i] != sccM[nxt])
            {
               indegree[sccM[nxt]]++;
            }
         }
      }

      int tmp;
      int a = 0;
      for (int i = 1; i <= sccN; i++)
      {
         if (!indegree[i])
         {
            tmp = i;
            a++;
         }
      }

      if (a > 1)
      {
         cout << "Confused"
              << "\n";
      }
      else
      {
         rep(i, V)
         {
            if (sccM[i] == tmp)
               printf("%d\n", i);
         }
      }
      cout << "\n";
   }

   return 0;
}