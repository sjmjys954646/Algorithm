//freopen("input.txt", "r", stdin);
//8940kb 112ms
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

int V, E;
vi graph[10002];
int visited[10002];
bool isCut[10002];
int num = 0;

int dfs(int here, bool isRoot)
{
    int child = 0;
    visited[here] = ++num;
    int ret = visited[here];

    for (int i = 0; i < graph[here].size(); i++)
    {
        int next = graph[here][i];
        if (visited[next])
        {
            ret = min(ret, visited[next]);
            continue;
        }

        child++;
        int prev = dfs(next, false);

        if (!isRoot && prev >= visited[here])
        {
            isCut[here] = true;
        }

        ret = min(ret, prev);
    }

    if (isRoot && child >= 2)
        isCut[here] = true;

    return ret;
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int cnt = 0;

    scanf("%d %d", &V, &E);

    rep(i, E)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    rep1(i, V)
    {
        if (!visited[i])
            dfs(i, true);
    }

    rep1(i, V)
    {
        if (isCut[i])
            cnt++;
    }

    printf("%d\n", cnt);

    rep1(i, V)
    {
        if (isCut[i])
            printf("%d ", i);
    }

    return 0;
}
