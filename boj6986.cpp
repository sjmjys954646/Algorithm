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

int N, K;
long long arr[100003];
long long arr2[100003];

void makeJeol()
{
   for (int i = 0; i < K; i++)
   {
      arr[i] = 0;
      arr[N - 1 - i] = 0;
   }
}

void makeBo()
{
   long long low = arr2[K];
   long long high = arr2[N - 1 - K];

   for (int i = 0; i < K; i++)
   {
      arr2[i] = low;
      arr2[N - 1 - i] = high;
   }
}

int main()
{
   cin >> N >> K;

   rep(i, N)
   {
      float tmp;
      cin >> tmp;
      arr[i] = tmp * 1000;
      arr2[i] = tmp * 1000;
   }

   sort(arr, arr + N);
   sort(arr2, arr2 + N);

   makeJeol();
   makeBo();

   long long sum = 0;
   long long sum2 = 0;

   rep(i, N)
   {
      sum += arr[i];
      sum2 += arr2[i];
   }
   sum /= (N - K * 2);
   sum2 /= N;

   if (sum % 10 >= 5)
      sum += 10;
   sum /= 10;
   cout << sum / 100 << '.' << (sum / 10) % 10 << sum % 10 << '\n';

   if (sum2 % 10 >= 5)
      sum2 += 10;
   sum2 /= 10;
   cout << sum2 / 100 << '.' << (sum2 / 10) % 10 << sum2 % 10 << '\n';

   return 0;
}