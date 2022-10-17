//5648kb 0ms
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#define X first
#define Y second

using namespace std;

typedef long long ll;

long long dist[100010];
int N, M;
int A, B, C, Q;
int ac[100002][22];
int depth[100002];
vector<pair<int, int>> graph[100002];

void dfs(int here, int par, long long d)
{
    depth[here] = depth[par] + 1;
    dist[here] = d;
    for (auto next : graph[here])
    {
        if (next.first == par)
            continue;
        dfs(next.first, here, d + next.second);
        ac[next.first][0] = here;
    }
}

int getlca(int x, int y)
{
    if (depth[x] > depth[y])
        swap(x, y);
    for (int i = 20; i >= 0; i--)
    {
        if (depth[y] - depth[x] >= (1 << i))
            y = ac[y][i];
    }
    if (x == y)
        return x;
    for (int i = 20; i >= 0; i--)
    {
        if (ac[x][i] != ac[y][i])
        {
            x = ac[x][i];
            y = ac[y][i];
        }
    }
    return ac[x][0];
}
int main()
{

    scanf("%d", &N);

    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d %d %d", &A, &B, &C);
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }
    dfs(1, 0, 0);
    for (int j = 1; j <= 20; j++)
    {
        for (int i = 1; i <= N; i++)
            ac[i][j] = ac[ac[i][j - 1]][j - 1];
    }
    scanf("%d", &M);
    while (M--)
    {
        scanf("%d", &Q);
        if (Q == 1)
        {
            scanf("%d %d", &A, &B);
            int lca = getlca(A, B);
            printf("%lld\n", dist[A] + dist[B] - 2 * dist[lca]);
        }
        else
        {
            scanf("%d%d%d", &A, &B, &C);
            int lca = getlca(A, B);
            int diff = depth[A] - depth[lca];
            if (diff + 1 >= C)
            {
                C--;
                for (int i = 20; i >= 0; i--)
                {
                    if ((1 << i) <= C)
                    {
                        C -= (1 << i);
                        A = ac[A][i];
                    }
                }
                printf("%d\n", A);
            }
            else
            {
                C = depth[B] - depth[lca] + 1 + diff - C;
                for (int i = 20; i >= 0; i--)
                {
                    if ((1 << i) <= C)
                    {
                        C -= (1 << i);
                        B = ac[B][i];
                    }
                }
                printf("%d\n", B);
            }
        }
    }
    return 0;
}
