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

int n, m, x, y;
int a, b;
int ans = -1;

int arr[3002][3002];
int visit[3002][3002];
int dX[4] = { 1,0,-1,0 };
int dY[4] = { 0,1,0,-1 };

void bfs()
{
    queue<pair<pii, int>> q;
    q.push({{ a,b }, 0 });
    visit[a][b] = 1;
    bool end = false;
    while (!q.empty())
    {
        if (end)
            break;

        int curX = q.front().F.S;
        int curY = q.front().F.F;
        int cost = q.front().S;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nX = curX + dX[i];
            int nY = curY + dY[i];

            if (nY < 0 || nY >= n || nX < 0 || nX >= m)
                continue;
            if (visit[nY][nX] != -1)
                continue;
            if (arr[nY][nX] == 1)
                continue;

            if (arr[nY][nX] == 3 || arr[nY][nX] == 4 || arr[nY][nX] == 5)
            {
                ans = cost + 1;
                end = true;
                break;
            }

            q.push({ {nY,nX},cost + 1 });;
            visit[nY][nX] = 1;
        }

    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(visit, -1, sizeof(visit));

    cin >> n >> m;

    rep(i, n)
    {
        string tmp;
        cin >> tmp;
        rep(j, m)
        {
            arr[i][j] = tmp[j] - '0';
            if (arr[i][j] == 2)
            {
                a = i; // starty
                b = j; // startx
            }
        }
    }


    bfs();

    if (ans == -1)
    {
        cout << "NIE";
    }
    else
    {
        cout << "TAK" << "\n" << ans;
    }

    return 0;
}