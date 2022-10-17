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

int par[52];

int find(int a)
{
   if (par[a] == a)
      return a;

   return par[a] = find(par[a]);
}

void merge(int a, int b)
{
   a = find(a);
   b = find(b);
   if (a != b)
      par[a] = b;
}

int main()
{
   int N, M;
   int personNum;
   vector<int> VpersonNum;
   vector<int> party[51];

   cin >> N >> M;

   cin >> personNum;

   for (int i = 1; i <= N; ++i)
   {
      par[i] = i;
   }

   rep(i, personNum)
   {
      int p;
      cin >> p;
      VpersonNum.push_back(p);
   }

   for (int t = 0; t < M; t++)
   {
      int l;
      cin >> l;
      int a, d;
      for (int i = 0; i < l; i++)
      {
         cin >> d;
         party[t].push_back(d);
         if (i == 0)
         {
            a = d;
            continue;
         }
         merge(a, d);
         a = d;
      }
   }

   int ans = 0;

   if (personNum == 0)
   {
      cout << M;
   }
   else
   {
      for (int i = 0; i < M; i++)
      {
         bool chk = true;
         for (int j = 0; j < party[i].size(); j++)
         {
            for (int k = 0; k < VpersonNum.size(); k++)
            {
               if (find(party[i][j]) == find(VpersonNum[k]))
               {
                  chk = false;
                  break;
               }
            }
            if (!chk)
               break;
         }
         if (chk)
            ans++;
      }

      cout << ans;
   }

   return 0;
}