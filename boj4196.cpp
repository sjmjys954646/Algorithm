//freopen("input.txt", "r", stdin);
//8940kb 112ms
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

int n, m;
vector<int> arr[100002];
bool visited[100002];
bool finish[100002];
stack<int> s;
int ans = 0;

void dfs(int start)
{
   visited[start] = true;
   for (int i = 0; i < arr[start].size(); i++)
   {
      if (visited[arr[start][i]] == false)
      {
         dfs(arr[start][i]);
      }
   }
   finish[start] = true;
   s.push(start);
}

int main()
{

   int testcase;
   scanf("%d", &testcase);

   while (testcase--)
   {
      while (!s.empty())
         s.pop();
      memset(visited, 0, sizeof(visited));
      for (int i = 0; i < 100002; i++)
         arr[i].clear();
      ans = 0;

      int A, B;

      scanf("%d %d", &n, &m);

      rep(i, m)
      {
         scanf("%d %d", &A, &B);
         arr[A].pb(B);
      }

      rep1(i, n)
      {
         if (!visited[i])
            dfs(i);
      }

      memset(visited, 0, sizeof(visited));
      while (!s.empty())
      {
         int t = s.top();
         s.pop();
         if (!visited[t])
         {
            dfs(t);
            ans++;
         }
      }

      printf("%d\n", ans);
   }

   return 0;
}
