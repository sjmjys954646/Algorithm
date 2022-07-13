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

int testcase;

int arr[7] = { 0, };

int main() 
{
    rep(i, 3)
    {
        int t;
        cin >> t;
        arr[t]++;
    }

    int cur;
    int ans = -1;
    int curnumMax = -1;
    rep1(i, 6)
    {
        if (arr[i] == 3)
        {
            cur = i;
            ans = 10000 + cur * 1000;
            break;
        }
        else if (arr[i] == 2)
        {
            cur = i;
            ans = 1000 + cur * 100;
            break;
        }
        else if(arr[i] == 1)
        {
            curnumMax = max(curnumMax, i);
        }
    }
    if (ans == -1)
        ans = curnumMax * 100;

    cout << ans;
    
}