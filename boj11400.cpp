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
vi graph[100002];
int visited[100002];
bool isCut[100002];
vector<pii> ans;
int num = 0;

int dfs(int here, int par)
{
    int child = 0;
    visited[here] = ++num;
    int ret = visited[here];

    for (int i = 0; i < graph[here].size(); i++)
    {
        int next = graph[here][i];
        if (next == par)
            continue;

        if (!visited[next])
        {
            int tmp = dfs(next, here);
            if (tmp > visited[here])
                ans.pb({min(here, next), max(here, next)});
            ret = min(tmp, ret);
        }
        else
            ret = min(visited[next], ret);
    }

    return ret;
}

int main()
{

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
            dfs(i, 0);
    }

    rep1(i, V)
    {
        if (isCut[i])
            cnt++;
    }
    sort(ans.begin(), ans.end());

    printf("%d\n", ans.size());

    for (auto i : ans)
        printf("%d %d\n", i.F, i.S);

    return 0;
}
