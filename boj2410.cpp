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

int cache[1000002][20] = {
    0,
};

int main()
{

   int N;

   scanf("%d", &N);

   rep(i, 20)
   {
      cache[0][i] = 1;
   }

   rep1(i, N)
   {
      cache[i][0] = 1;

      rep1(j, 20)
      {
         if (i >= (1 << j))
            cache[i][j] = (cache[i][j - 1] + cache[i - (1 << j)][j]) % 1000000000;
         else
            cache[i][j] = cache[i][j - 1];
      }
   }

   printf("%d", cache[N][19]);

   return 0;
}