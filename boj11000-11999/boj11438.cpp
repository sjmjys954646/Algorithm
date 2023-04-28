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

int N, M;

int depth[100002];
int ac[100002][22];
vector<int> graph[100002];
int maxhi;

void getTree(int here, int par)
{
    depth[here] = depth[par] + 1;
    ac[here][0] = par;

    for (int i = 1; i <= maxhi; i++)
    {
        int tmp = ac[here][i - 1];
        ac[here][i] = ac[tmp][i - 1];
    }

    for (int i = 0; i < graph[here].size(); i++)
    {
        int there = graph[here][i];
        if (there != par)
            getTree(there, here);
    }
}

int main()
{

    memset(depth, 0, sizeof(depth));

    int a, b;

    scanf("%d", &N);

    maxhi = (int)floor(log2(100002));

    for (int i = 0; i < N - 1; i++)
    {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    getTree(1, 0);

    scanf("%d", &M);

    while (M--)
    {
        scanf("%d %d", &a, &b);

        if (depth[a] != depth[b])
        {
            if (depth[a] > depth[b])
                swap(a, b);

            for (int i = maxhi; i >= 0; i--)
            {
                if (depth[a] <= depth[ac[b][i]])
                {
                    b = ac[b][i];
                }
            }
        }

        int ans = a;

        if (a != b)
        {
            for (int i = maxhi; i >= 0; i--)
            {
                if (ac[a][i] != ac[b][i])
                {
                    a = ac[a][i];
                    b = ac[b][i];
                }
                ans = ac[a][i];
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}