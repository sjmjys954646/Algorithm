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
#include <typeinfo>
#include <bitset>

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

int testcase;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pii x, y, z;

    cin >> x.first >> x.second;

    cin >> y.first >> y.second;

    cin >> z.first >> z.second;

    int a = abs(y.second - x.second);
    int b = abs(y.first - x.first);
    int c = abs(z.second - x.second);
    int d = abs(z.first - x.first);

   

   if (a * d == b * c)
       cout << "WHERE IS MY CHICKEN?";
   else
       cout << "WINNER WINNER CHICKEN DINNER!";



    return 0;
}