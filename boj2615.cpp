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

int visited[20][20];
int arr[20][20];
int ansX, ansY;

int dirX[4] = {1, 0, 1, -1};
int dirY[4] = {0, 1, 1, 1};

int dfs(int curX, int curY, int color, int dir, int depth)
{

    if (curX < 0 || curY < 0 || curX > 19 || curY > 19)
        return depth - 1;

    if (arr[curX][curY] != color)
        return depth - 1;

    if (visited[curX][curY] == dir)
        return depth - 1;

    visited[curX][curY] = dir;

    int nextX = curX + dirX[dir];
    int nextY = curY + dirY[dir];
    depth = dfs(nextX, nextY, color, dir, depth + 1);

    return depth;
}

bool judge(int color)
{
    int result = 0;

    rep(j, 20)
    {
        rep(i, 20)
        {
            if (arr[i][j] != color)
                continue;

            result = dfs(i, j, color, 0, 1);
            if (result == 5)
            {
                ansX = j;
                ansY = i;
                return true;
            }
            result = dfs(i, j, color, 1, 1);
            if (result == 5)
            {
                ansX = j;
                ansY = i;
                return true;
            }
            result = dfs(i, j, color, 2, 1);
            if (result == 5)
            {
                ansX = j;
                ansY = i;
                return true;
            }
            result = dfs(i, j, color, 3, 1);
            if (result == 5)
            {
                ansX = j;
                ansY = i;
                return true;
            }
        }
    }

    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);

    memset(visited, -1, sizeof(visited));

    rep(i, 19)
    {
        rep(j, 19)
            scanf("%d", &arr[i][j]);
    }

    if (judge(1))
    {
        printf("1\n");
        printf("%d %d", ansY + 1, ansX + 1);
    }
    else if (judge(2))
    {
        printf("2\n");
        printf("%d %d", ansY + 1, ansX + 1);
    }
    else
    {
        printf("0");
    }

    return 0;
}