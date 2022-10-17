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

int charArr[27];
int numArr[15];

int main()
{
   char a;
   int b;
   int quad = 0;
   int triple = 0;
   int pair = 0;
   int pair2 = 0;
   int flush = 0;
   int straight = 0;
   int maxi = -1;

   for (int i = 0; i < 5; i++)
   {
      cin >> a >> b;
      charArr[a - 'A']++;
      numArr[b]++;
      maxi = max(maxi, b);
   }

   for (int i = 1; i <= 13; i++)
   {
      if (numArr[i] == 2)
      {
         if (pair != 0)
            pair2 = i;
         else
            pair = i;
      }
      else if (numArr[i] == 3)
         triple = i;
      else if (numArr[i] == 4)
         quad = i;
   }

   for (int i = 0; i <= 26; i++)
   {
      if (charArr[i] == 5)
         flush = 1;
   }

   for (int i = 1; i <= 9; i++)
   {
      if (numArr[i] && numArr[i + 1] && numArr[i + 2] && numArr[i + 3] && numArr[i + 4])
      {
         straight = 1;
      }
   }

   if (flush && straight)
   {
      printf("%d", 900 + maxi);
   }
   else if (flush)
   {
      printf("%d", 600 + maxi);
   }
   else if (straight)
   {
      printf("%d", 500 + maxi);
   }
   else if (quad != 0)
   {
      printf("%d", 800 + quad);
   }
   else if (triple != 0 && pair != 0)
   {
      printf("%d", 700 + 10 * triple + pair);
   }
   else if (triple != 0)
   {
      printf("%d", 400 + triple);
   }
   else if (pair != 0 && pair2 != 0)
   {
      printf("%d", 300 + 10 * max(pair, pair2) + min(pair, pair2));
   }
   else if (pair != 0)
   {
      printf("%d", 200 + pair);
   }
   else
      printf("%d", 100 + maxi);

   return 0;
}