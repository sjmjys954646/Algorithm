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

struct Nation
{
   int NationNum;
   int Gold;
   int Silver;
   int Bronze;
};

bool cmp(Nation a, Nation b)
{
   if (a.Gold != b.Gold)
      return a.Gold > b.Gold;
   else
   {
      if (a.Silver != b.Silver)
         return a.Silver > b.Silver;
      else
      {
         return a.Bronze > b.Bronze;
      }
   }
}

bool sameCheck(Nation a, Nation b)
{
   bool check = true;
   if (a.Gold != b.Gold)
      check = false;
   if (a.Silver != b.Silver)
      check = false;
   if (a.Bronze != b.Bronze)
      check = false;
   return check;
}

int N, K;
int NationRating[1002];

int main()
{
   vector<Nation> v;

   cin >> N >> K;

   rep(i, N)
   {
      Nation nn;
      cin >> nn.NationNum >> nn.Gold >> nn.Silver >> nn.Bronze;
      v.push_back(nn);
   }

   sort(v.begin(), v.end(), cmp);

   int rating = 1;
   int currate = rating;

   for (int i = 0; i < v.size(); i++)
   {
      NationRating[v[i].NationNum] = currate;

      rating++;
      if (sameCheck(v[i], v[i + 1]))
         continue;
      else
         currate = rating;
   }

   cout << NationRating[K];

   return 0;
}