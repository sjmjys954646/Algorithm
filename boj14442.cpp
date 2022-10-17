#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stdio.h>
#include <string>
#include<string.h>
#include <math.h>
#include <map>
#include <queue>
#define X first
#define Y second
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

char graph[1002][1002];
int path[1002][1002][11];
int N, M, K;

int dX[4] = { -1,1,0,0 };
int dY[4] = { 0,0,-1,1 };

struct a
{
    int x, y, w;
};


int bfs()
{
    queue<a> q;
    q.push({ 0, 0, 0 });
    path[0][0][0] = 1;

    while (!q.empty())
    {
        int qX = q.front().x;
        int qY = q.front().y;
        int qW = q.front().w;
        q.pop();

        if (qX == N - 1 && qY == M - 1)
        {
            return path[qX][qY][qW];
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = qX + dX[i], ny = qY + dY[i], nw = qW + 1;
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (path[nx][ny][qW]) continue;
            if (graph[nx][ny] == '0')
            {
                path[nx][ny][qW] = path[qX][qY][qW] + 1;
                q.push({ nx, ny, qW });
            }
            if (graph[nx][ny] == '1' && nw <= K && !path[nx][ny][nw])
            {
                path[nx][ny][nw] = path[qX][qY][qW] + 1;
                q.push({ nx, ny, nw });
            }
        }
    }
    return -1;
}

int main()
{

    scanf("%d %d %d", &N, &M, &K);

    for (int i = 0; i < N; i++) {
        scanf("%s", graph[i]);
    }

    printf("%d", bfs());

    return 0;
}
