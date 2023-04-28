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

int N, M, K;

int arr[17][17];

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   cin >> N >> M >> K;

   rep(i, N)
   {
      rep(j, M)
      {
         arr[i][j] = 1;
      }
   }
   int kY = 0;
   int kX = 0;

   if (K != 0)
   {
      kY = K / M;
      kX = K - K / M * M - 1;

      if (K % M == 0)
      {
         kY = K / M - 1;
         kX = M - 1;
      }
   }

   if (K == 0)
   {
      for (int i = 1; i < N; i++)
      {
         for (int j = 1; j < M; j++)
         {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
         }
      }
   }
   else
   {
      for (int i = 1; i <= kY; i++)
      {
         for (int j = 1; j <= kX; j++)
         {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
         }
      }

      int tmp = arr[kY][kX];

      for (int i = kY; i < N; i++)
      {
         arr[i][kX] = tmp;
      }
      for (int i = kX; i < M; i++)
      {
         arr[kY][i] = tmp;
      }

      for (int i = kY + 1; i < N; i++)
      {
         for (int j = kX + 1; j < M; j++)
         {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
         }
      }
   }

   cout << arr[N - 1][M - 1];

   return 0;
}