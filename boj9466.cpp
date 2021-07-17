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

int graph[100001];
bool visited[100001];
bool fin[100001];
int ans;

void dfs(int start)
{
    visited[start] = true;

    int nt = graph[start];

    if (!visited[nt])
        dfs(nt);
    else if (!fin[nt])
    {
        for (int i = nt; i != start; i = graph[i])
        {
            ans++;
        }
        ans++;
    }
    fin[start] = true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int testcase;

    scanf("%d", &testcase);

    while (testcase--)
    {
        int N;
        ans = 0;
        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));
        memset(fin, 0, sizeof(fin));

        scanf("%d", &N);

        rep(i, N)
        {
            int tmp;
            scanf("%d", &tmp);
            graph[i] = tmp - 1;
        }

        rep(i, N)
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }

        printf("%d\n", N - ans);
    }

    return 0;
}