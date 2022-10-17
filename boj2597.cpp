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

int main()
{
   float len;
   float point[3][2];

   cin >> len;

   for (int i = 0; i < 3; i++)
   {
      cin >> point[i][0] >> point[i][1];
      if (point[i][0] > point[i][1])
         swap(point[i][0], point[i][1]);
   }

   for (int i = 0; i < 3; i++)
   {
      if (point[i][0] == point[i][1])
         continue;
      float mid = (point[i][0] + point[i][1]) / 2.f;
      if (mid < len - mid)
      {
         for (int j = i + 1; j < 3; j++)
         {
            for (int k = 0; k < 2; k++)
            {
               if (point[j][k] < mid)
                  point[j][k] = mid - point[j][k];
               else
                  point[j][k] -= mid;
            }
            if (point[i][0] > point[i][1])
               swap(point[i][0], point[i][1]);
         }
         len = len - mid;
      }
      else
      {
         for (int j = i + 1; j < 3; j++)
         {
            for (int k = 0; k < 2; k++)
            {
               if (mid < point[j][k])
                  point[j][k] = mid - (point[j][k] - mid);
            }

            if (point[i][0] > point[i][1])
               swap(point[i][0], point[i][1]);
         }
         len = mid;
      }
   }
   printf("%.1f", len);
   return 0;
}
