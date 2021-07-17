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
vector<int> arr[10002];
bool finished[10002]; // scc가 만들어됬는지
stack<int> S;
int num = 0;
int sccN = 0;
int visited[10002]; // 방문 번호
vector<int> scc[10002];

int dfs(int start)
{
    visited[start] = ++num;
    S.push(start);
    int ret = visited[start];

    for (int next : arr[start])
    {
        if (!visited[next])
            ret = min(ret, dfs(next));
        else if (!finished[next])
            ret = min(ret, visited[next]);
    }

    if (ret == visited[start])
    {
        while (true)
        {
            int tmp = S.top();
            S.pop();
            scc[sccN].pb(tmp);
            finished[tmp] = true;
            if (tmp == start)
                break;
        }
        sort(scc[sccN].begin(), scc[sccN].end());
        sccN++;
    }

    return ret;
}

int main()
{
    freopen("input.txt", "r", stdin);
    memset(finished, 0, sizeof(finished));
    memset(visited, 0, sizeof(visited));

    int A, B;

    scanf("%d %d", &V, &E);

    rep(i, E)
    {
        scanf("%d %d", &A, &B);
        arr[A].pb(B);
    }

    rep1(i, V)
    {
        if (!visited[i])
            dfs(i);
    }

    sort(scc, scc + sccN);

    printf("%d\n", sccN);
    for (int i = 0; i < sccN; i++)
    {
        for (int j : scc[i])
        {
            printf("%d ", j);
        }
        printf("-1\n");
    }

    return 0;
}
