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

int a, b;

int GCD(int a, int b)
{
   int temp;
   while (b)
   {
      temp = a % b;
      a = b;
      b = temp;
   }
   return a;
}

int main()
{
   scanf("%d %d", &a, &b);

   int k = b / a;
   int ans;

   for (int i = 1; i * i <= k; i++)
   {
      if (k % i == 0)
      {
         if (GCD(i, k / i) == 1)
            ans = i;
      }
   }

   printf("%d %d", ans * a, k / ans * a);

   return 0;
}