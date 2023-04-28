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

int N;
vi v;
int arr[10001];

int main()
{
   cin >> N;

   rep(i, N)
   {
      int tmp;
      cin >> tmp;
      v.push_back(tmp);
   }

   if (N == 1)
   {
      cout << v[0];
      return 0;
   }

   sort(v.begin(), v.end());

   for (int i = 1; i < 10001; i++)
   {

      int sum = 0;
      for (int j = 0; j < N; j++)
      {
         sum += (abs(v[j] - i));
      }
      arr[i] = sum;
      // cout << i << " " << sum << "\n";
   }

   int maxi = INF;
   int ans;
   for (int i = 1; i < 10001; i++)
   {
      if (maxi > arr[i])
      {
         ans = i;
         maxi = arr[i];
      }
   }

   cout << ans;

   return 0;
}