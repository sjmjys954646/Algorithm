//freopen("input.txt", "r", stdin);
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

int N, M;
int arr[100002] = {
    0,
};
int cache[100002] = {
    0,
};
int main()
{

   scanf("%d %d", &N, &M);

   rep1(i, N)
   {
      scanf("%d", &arr[i]);
      cache[i] = arr[i] + cache[i - 1];
   }

   rep(i, M)
   {
      int a, b;
      scanf("%d %d", &a, &b);

      printf("%d\n", cache[b] - cache[a - 1]);
   }

   return 0;
}