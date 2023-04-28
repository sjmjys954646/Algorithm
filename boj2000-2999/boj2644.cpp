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

vector<int> arr[102];
int n, m, x, y;
int a, b;
int visit[102];

void dfs(int start, int depth)
{
    visit[start] = depth;

    for (int i = 0; i < arr[start].size(); i++)
    {
        int next = arr[start][i];

        if (visit[next] != -1)
            continue;

        dfs(next, depth + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(visit, -1, sizeof(visit));

    cin >> n;
    cin >> a >> b;
    cin >> m;

    rep(i, m)
    {
        cin >> x >> y;
        arr[x].pb(y);
        arr[y].pb(x);
    }
    
    dfs(a,0);

    cout << visit[b];

    return 0;
}