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
#include <deque>
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
int cache[1002][1002];
int arr[1002][1002];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    cin >> n >> m;

    rep(i, n)
    {
        rep(j, m)
            cin >> arr[i][j];
    }

    rep(i, n)
    {
        rep(j, m)
        {
            cache[i][j + 1] = max(cache[i][j] + arr[i][j], cache[i][j + 1]);
            cache[i+1][j] = max(cache[i][j] + arr[i][j], cache[i+1][j]);
            cache[i+1][j + 1] = max(cache[i][j] + arr[i][j], cache[i+1][j + 1]);
        }
    }
   
    cout << cache[n - 1][m - 1] + arr[n-1][m-1];
    

    return 0;
}