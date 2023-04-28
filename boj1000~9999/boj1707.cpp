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

vector<int> graph[20002];
int arr[20002];
int V, E;

bool bfs()
{
    queue<int> q;

    for (int t = 1; t <= V; t++)
    {
        if (arr[t] == 0)
        {
            q.push(t);
            arr[t] = 1;

            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                for (int i = 0; i < graph[cur].size(); i++)
                {
                    int tmp = graph[cur][i];
                    if (arr[tmp] == 0)
                    {
                        q.push(tmp);
                        arr[tmp] = arr[cur] == 1 ? 2 : 1;
                    }
                    else
                    {
                        if (arr[tmp] == arr[cur])
                        {
                            return false;
                        }
                    }
                }
            }
        }   
    }
    return true;
}

int main()
{
    int testcase;

    scanf("%d", &testcase);

    while (testcase--)
    {
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < 20001; i++)
            graph[i].clear();

        scanf("%d %d", &V, &E);

        for (int i = 0; i < E; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        if (bfs())
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}