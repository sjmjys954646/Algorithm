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
int arr[102];

int main()
{

   int a, b;
   int t;

   scanf("%d", &N);

   rep1(i, N)
   {
      int tmp;
      scanf("%d", &tmp);
      if (tmp == 0)
         arr[i] = -1;
      else
         arr[i] = 1;
   }

   scanf("%d", &t);

   while (t--)
   {
      scanf("%d %d", &a, &b);
      if (a == 1)
      {
         for (int i = b; i <= N; i += b)
         {
            arr[i] = -arr[i];
         }
      }
      else if (a == 2)
      {
         int front = b;
         int back = b;
         while (true)
         {
            if (front == 0 || back == N + 1)
               break;

            if (arr[front] != arr[back])
               break;

            arr[front] = -arr[front];
            arr[back] = -arr[back];
            front--;
            back++;
         }
         arr[b] = -arr[b];
      }
   }
   rep1(i, N)
   {
      if (arr[i] == -1)
         printf("0 ");
      else
         printf("1 ");

      if (i % 20 == 0)
         printf("\n");
   }

   return 0;
}