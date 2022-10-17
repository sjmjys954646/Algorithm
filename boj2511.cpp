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

int arr[2][11];
int res[11];

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   int sumA = 0;
   int sumB = 0;

   rep(i, 10)
   {
      cin >> arr[0][i];
   }

   rep(i, 10)
   {
      cin >> arr[1][i];
   }

   rep(i, 10)
   {
      if (arr[0][i] > arr[1][i])
      {
         res[i] = -1;
         sumA += 3;
      }
      else if (arr[0][i] < arr[1][i])
      {
         res[i] = 1;
         sumB += 3;
      }
      else
      {
         res[i] = 0;
         sumA += 1;
         sumB += 1;
      }
   }

   cout << sumA << " " << sumB << "\n";
   if (sumA > sumB)
   {
      cout << "A";
      return 0;
   }
   else if (sumA < sumB)
   {
      cout << "B";
      return 0;
   }
   else
   {
      for (int i = 9; i >= 0; i--)
      {
         if (arr[0][i] > arr[1][i])
         {
            cout << "A";
            return 0;
         }
         else if (arr[0][i] < arr[1][i])
         {
            cout << "B";
            return 0;
         }
      }
      cout << "D";
      return 0;
   }

   return 0;
}