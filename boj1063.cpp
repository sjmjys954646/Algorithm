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

int arr[8][8];
pii dol;
pii king;
int dX[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dY[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int converter(string a)
{
   if (a == "T")
      return 0;
   else if (a == "RT")
      return 1;
   else if (a == "R")
      return 2;
   else if (a == "RB")
      return 3;
   else if (a == "B")
      return 4;
   else if (a == "LB")
      return 5;
   else if (a == "L")
      return 6;
   else if (a == "LT")
      return 7;

   return 0;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   memset(arr, 0, sizeof(arr));

   string a, b;
   int c;

   cin >> a >> b >> c;

   king = make_pair((int)(a[0] - 'A'), (int)(a[1] - '0' - 1));
   dol = make_pair((int)(b[0] - 'A'), (int)(b[1] - '0' - 1));

   while (c--)
   {
      bool check = false;

      cin >> a;
      int order = converter(a);
      int qX = dX[order];
      int qY = dY[order];

      // cout << qX << qY << "\n";

      if (dol.F - king.F == qX && dol.S - king.S == qY)
         check = true;

      if (check)
      {
         int nX = king.F + qX;
         int nY = king.S + qY;
         int dolX = dol.F + qX;
         int dolY = dol.S + qY;

         if (nX < 0 || nY < 0 || nX >= 8 || nY >= 8)
            continue;

         if (dolX < 0 || dolY < 0 || dolX >= 8 || dolY >= 8)
            continue;

         king = {nX, nY};
         dol = {dolX, dolY};
      }
      else
      {
         int nX = king.F + qX;
         int nY = king.S + qY;

         if (nX < 0 || nY < 0 || nX >= 8 || nY >= 8)
            continue;

         king = {nX, nY};
      }

      // cout << c << "\n"
      //      << (char)(king.F + 'A') << king.S << "\n"
      //      << (char)(dol.F + 'A') << dol.S << "\n";
   }

   cout << (char)(king.F + 'A') << king.S + 1 << "\n"
        << (char)(dol.F + 'A') << dol.S + 1;

   return 0;
}