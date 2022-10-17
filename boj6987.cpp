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

int arr[6][6];

int score[6][3];
int games[6][3];
int ans;
vector<pii> teams;

void dfs(int idx)
{
   if (idx == 15)
   {
      for (int i = 0; i < 6; i++)
         for (int j = 0; j < 3; j++)
            if (score[i][j] != games[i][j])
               return;
      ans = 1;
      return;
   }

   int t1 = teams[idx].first;
   int t2 = teams[idx].second;
   games[t1][0]++;
   games[t2][2]++;
   dfs(idx + 1);
   games[t1][0]--;
   games[t2][2]--;

   games[t1][2]++;
   games[t2][0]++;
   dfs(idx + 1);
   games[t1][2]--;
   games[t2][0]--;

   games[t1][1]++;
   games[t2][1]++;
   dfs(idx + 1);
   games[t1][1]--;
   games[t2][1]--;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   for (int i = 0; i < 6; i++)
   {
      for (int j = i + 1; j < 6; j++)
      {
         teams.push_back({i, j});
      }
   }

   for (int i = 0; i < 4; i++)
   {
      ans = 0;
      for (int j = 0; j < 6; j++)
      {
         for (int k = 0; k < 3; k++)
         {
            cin >> score[j][k];
            games[j][k] = 0;
         }
      }

      dfs(0);
      cout << ans << ' ';
   }

   return 0;
}