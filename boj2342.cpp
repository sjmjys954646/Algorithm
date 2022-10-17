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

const int INF = 1e9;

int testcase;

int N, M, K, Q, L;

int cache[100004][5][5];
vi v;

int dir[5][5] = {
    {0,2,2,2,2},
    {0,1,3,4,3},
    {0,3,1,3,4},
    {0,4,3,1,3},
    {0,3,4,3,1}
};

int dp(int idx, int l, int r) 
{
    if (idx == N)
        return 0;

    int& ret = cache[idx][l][r];

    if (ret)
        return ret;

    int next = v[idx];
    ret = INF;

    if (next != r)//right move
        ret = min(ret, dp(idx + 1, next, r) + dir[l][next]);
    if (next != l)//left move
        ret = min(ret, dp(idx + 1, l, next) + dir[r][next]);

    return ret;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    memset(cache, 0, sizeof(cache));

    while (true)
    {
        int n;

        cin >> n;

        if (!n)
            break;
        v.push_back(n);
    }

    N = v.size();

    cout << dp(0,0,0);

    return 0;
}
