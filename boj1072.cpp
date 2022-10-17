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

const int INF = INT_MAX;

int testcase;

ull N, M;
ull k;


int check(ull mid)
{
    ull p =(M + mid) * 100 / (N + mid);

    if (p <= k)
        return 1;
    else
        return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    k = M * 100 / N;
    
    if (k == 100 || k == 99)
    {
        cout << -1;
        return 0;
    }

    ull hi = 1000000000;
    ull lo = 0;
    while (lo + 1 < hi)
    {
        ull mid = (lo + hi) / 2;
        if (check(mid))
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }

    cout <<  hi;

    return 0;
}