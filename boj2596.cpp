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

string interpreter[8] = {"000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010"};
string input;
string ans = "";

char interpreting(string str)
{
   char find = 'X';
   for (int i = 0; i < 8; i++)
   {
      int dif = 0;

      for (int j = 0; j < 6; j++)
      {
         if (str[j] != interpreter[i][j])
         {
            dif++;
         }
      }

      if (dif >= 2)
         continue;

      find = 'A' + i;
   }

   return find;
}

int main()
{
   int N;

   cin >> N;

   cin >> input;

   for (int i = 0; i < N; i++)
   {
      string tmp = input.substr(i * 6, 6);
      char res = interpreting(tmp);
      if (res == 'X')
      {
         cout << i + 1;
         return 0;
         break;
      }

      ans += res;
   }
   cout << ans;
   return 0;
}
