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

int rec[102];

int num;
int order;

bool cmp(pii a, pii b)
{
   return a.second < b.second;
}

int main()
{
   int input;

   cin >> num >> order;

   vector<pair<int, int>> tul; //오래됬는지 이름

   for (int second = 0; second < order; second++)
   {
      bool check = false;
      cin >> input;

      for (int i = 0; i < tul.size(); i++)
      {
         if (tul[i].S == input)
         {
            rec[input]++;
            check = true;
         }
      }

      if (check)
         continue;

      if (tul.size() < num)
      {
         tul.push_back({second, input});
         rec[input] = 0;
         check = true;
      }

      if (check)
         continue;

      int hubo = 0;
      int huboRec = rec[tul[0].S];
      int huboSec = tul[0].F;
      for (int i = 1; i < tul.size(); i++)
      {
         if (rec[tul[i].S] < huboRec)
         {
            hubo = i;
            huboRec = rec[tul[i].S];
            huboSec = tul[i].F;
         }
         else if (rec[tul[i].S] == huboRec)
         {
            if (tul[i].F < huboSec)
            {
               hubo = i;
               huboRec = rec[tul[i].S];
               huboSec = tul[i].F;
            }
         }
      }

      rec[tul[hubo].S] = 0;
      tul[hubo].F = second;
      tul[hubo].S = input;
   }

   sort(tul.begin(), tul.end(), cmp);

   for (auto x : tul)
      cout << x.S << " ";
   cout << "\n";

   return 0;
}