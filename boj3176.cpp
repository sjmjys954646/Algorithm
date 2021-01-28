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
int N;
int K;
vector<pair<int, int>> graph[100002];
int root;
int maxhi;
int depth[100002];
int ac[100002][22], low[100002][22], high[100002][22];
bool visited[100002];
int Shortest;
int Longest;
void dfs(int here, int d)
{
    visited[here] = true;
    depth[here] = d;
    for (int i = 0; i < graph[here].size(); i++)
    {
        int there = graph[here][i].first;
        int cost = graph[here][i].second;
        if (visited[there])
            continue;
        dfs(there, d + 1);
        ac[there][0] = here;
        low[there][0] = cost;
        high[there][0] = cost;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    int A, B, C;
    memset(depth, 0, sizeof(depth));
    maxhi = (int)floor(log2(100002));
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d %d %d", &A, &B, &C);
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }
    dfs(1, 0);
    for (int j = 1; j <= maxhi; j++)
    {
        for (int i = 1; i <= N; i++)
        {
            int tmp = ac[i][j - 1];
            ac[i][j] = ac[tmp][j - 1];
            low[i][j] = min(low[i][j - 1], low[tmp][j - 1]);
            high[i][j] = max(high[i][j - 1], high[tmp][j - 1]);
        }
    }
    scanf("%d", &K);
    while (K--)
    {
        Shortest = 987654321;
        Longest = -1;
        scanf("%d %d", &A, &B);
        if (depth[A] != depth[B])
        {
            if (depth[A] > depth[B])
                swap(A, B);
            for (int i = maxhi; i >= 0; i--)
            {
                if (depth[B] - depth[A] >= (1 << i))
                {
                    Longest = max(Longest, high[B][i]);
                    Shortest = min(Shortest, low[B][i]);
                    B = ac[B][i];
                }
            }
        }
        if (A == B)
        {
            printf("%d %d\n", Shortest, Longest);
            continue;
        }
        for (int i = maxhi; i >= 0; i--)
        {
            if (ac[A][i] != ac[B][i])
            {
                Longest = max(Longest, max(high[A][i], high[B][i]));
                Shortest = min(Shortest, min(low[A][i], low[B][i]));
                A = ac[A][i];
                B = ac[B][i];
            }
        }
        Longest = max(Longest, max(high[A][0], high[B][0]));
        Shortest = min(Shortest, min(low[A][0], low[B][0]));
        printf("%d %d\n", Shortest, Longest);
    }
    return 0;
}