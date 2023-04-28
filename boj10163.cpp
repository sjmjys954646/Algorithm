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

int arr[1002][1002];
int num[200];

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   int N;

   cin >> N;

   memset(arr, sizeof(arr), 0);

   rep1(t, N)
   {
      int a, b, row, column;

      cin >> a >> b >> row >> column;

      rep(i, column)
      {
         rep(j, row)
         {
            arr[b + i][a + j] = t;
         }
      }
   }

   rep1(t, N)
   {
      int sum = 0;
      rep(i, 1001)
      {
         rep(j, 1001)
         {
            if (arr[i][j] == t)
               sum++;
         }
      }
      num[t] = sum;
   }

   rep1(t, N)
   {
      cout << num[t] << "\n";
   }

   return 0;
}