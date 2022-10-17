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

int N;

int main()
{

   scanf("%d", &N);

   vector<pii> pillar(N + 1); //가로index 세로
   int ans = 0;

   rep(i, N)
   {
      cin >> pillar[i].S >> pillar[i].F;
   }

   sort(pillar.begin(), pillar.end(), greater<>());

   int left = pillar[0].S;
   int right = pillar[0].S;

   ans += pillar[0].F;

   for (int i = 1; i < N; i++)
   {
      if (pillar[i].S > right)
      {
         ans += pillar[i].F * (pillar[i].S - right);
         right = pillar[i].S;
      }
      else if (pillar[i].S < left)
      {
         ans += pillar[i].F * (left - pillar[i].S);
         left = pillar[i].S;
      }
   }

   cout << ans;

   return 0;
}