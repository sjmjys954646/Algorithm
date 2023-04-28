// freopen("input.txt", "r", stdin);
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
#include <deque>
#include <stack>
#include <cstring>
#include <list>
#include <set>
#include <string.h>
#include <map>
#include <limits.h>
#include <stdlib.h>
#include <typeinfo>
#include <bitset>

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

const int INF = INT_MAX;

int testcase;

typedef struct {
    int x, y, cost, jump;
}t;

int n, m;
int a, b;
int jump;
int ans = -1;

int arr[202][202];
int visit[202][202];
int dX[4] = { 1,0,-1,0 };
int dY[4] = { 0,1,0,-1 };
int horseX[8] = { -1,-2,-2,-1,1,2,2,1 };
int horseY[8] = { -2,-1,1,2,-2,-1,1,2 };

void bfs()
{
    queue<t> q;
    q.push({0,0,0,jump });
    visit[0][0] = jump;

    while (!q.empty())
    {
        int curX = q.front().x;
        int curY = q.front().y;
        int cost = q.front().cost;
        int curJump = q.front().jump;
        q.pop();

        if (curX == n - 1 && curY == m - 1)
        {
            ans = cost;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nX = curX + dX[i];
            int nY = curY + dY[i];

            if (nY < 0 || nY >= m || nX < 0 || nX >= n)
                continue;
            if (visit[nY][nX] >= curJump)
                continue;
            if (arr[nY][nX] == 1)
                continue;

            q.push({ nX,nY,cost + 1,curJump});
            visit[nY][nX] = curJump;
        }

        if (curJump)
        {
            for (int i = 0; i < 8; i++)
            {
                int nY = curY + horseX[i];
                int nX = curX + horseY[i];
                if (nY < 0 || nY >= m || nX < 0 || nX >= n)
                    continue;
                if (visit[nY][nX] >= curJump - 1)
                    continue;
                if (arr[nY][nX] == 1)
                    continue;

                q.push({ nX,nY,cost + 1,curJump - 1});
                visit[nY][nX] = curJump - 1;
            }
        }
    }

    ans = -1;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(visit, -1, sizeof(visit));

    cin >> jump;

    cin >> n >> m;

    rep(i, m)
    {
        rep(j, n)
        {
            cin >> arr[i][j];
        }
    }

    bfs();

    cout << ans;

    return 0;
}