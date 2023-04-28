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

int n, m;
int a, b;
int jump;
int ans = -1;
int x, y;
int t;

vector<pii> arr;
int visit[102];
int dX[4] = { 1,0,-1,0 };
int dY[4] = { 0,1,0,-1 };

void bfs()
{
    queue<pii> q;
    q.push({ arr[0].F, arr[0].S }); //Y  X
    visit[0] = 1;

    while (!q.empty())
    {
        int curX = q.front().S;
        int curY = q.front().F;
        q.pop();

        if (curX == arr[t + 1].S && curY == arr[t + 1].F)
        {
            ans = 1;
            return;
        }

        for (int i = 1; i < arr.size(); i++)
        {
            if (visit[i] != -1)
                continue;
            
            if ((abs(arr[i].F - curY) + abs(arr[i].S - curX)) > 1000)
                continue;
             
            q.push({ arr[i].F, arr[i].S });
            visit[i] = 1;
        }
    }
    ans = -1;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> testcase;

    while (testcase--)
    {
        arr.clear();
        memset(visit, -1, sizeof(visit));
        ans = -1;

        cin >> t;

        rep(i, t + 2)
        {
            cin >> n >> m;
            arr.push_back({ m,n });// Y X
        }

        bfs();

        if (ans == 1)
        {
            cout << "happy\n";
        }
        else
        {
            cout << "sad\n";
        }
    }

    return 0;
}