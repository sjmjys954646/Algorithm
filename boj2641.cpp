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

int len;
int N;
string standard;
vector<string> pos;
string hubo[102];
int converter[5] = {0, 3, 4, 1, 2};

int main()
{

   int tmp;

   scanf("%d", &len);

   rep(i, len)
   {
      cin >> tmp;
      standard += (tmp + '0');
   }

   scanf("%d", &N);

   rep(j, N)
   {
      rep(i, len)
      {
         cin >> tmp;
         hubo[j] += (tmp + '0');
      }
   }

   pos.push_back(standard);
   rep(i, len - 1)
   {
      string t = pos[i].substr(1, len - 1);
      t.push_back(pos[i].front());
      pos.push_back(t);
   }

   string tmps;
   rep(i, len)
   {
      tmps += (converter[(standard[len - i - 1] - '0')] + '0');
   }

   pos.push_back(tmps);
   for (int i = len; i < len * 2; i++)
   {
      string t = pos[i].substr(1, len - 1);
      t.push_back(pos[i].front());
      pos.push_back(t);
   }

   int ans = 0;
   vector<int> vans;
   rep(i, N)
   {
      if (find(pos.begin(), pos.end(), hubo[i]) != pos.end())
      {
         ans++;
         vans.pb(i);
      }
   }

   cout << ans << "\n";
   rep(i, ans)
   {
      rep(j, len)
      {
         cout << hubo[vans[i]][j] << " ";
      }
      cout << "\n";
   }

   return 0;
}