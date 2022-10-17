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
int ans = INF;
int realans;
vi arr[102];
int visit[120];

void bfs(int start)
{
    queue<pii> q;
    q.push({ start, 0 });
    visit[start] = 0;

    while (!q.empty())
    {
        int cur = q.front().F;
        int cost = q.front().S;
        q.pop();

        for (int i = 0; i < arr[cur].size(); i++)
        {
            int next = arr[cur][i];

            if (visit[next] != -1)
                continue;


            q.push({next,cost + 1 });
            visit[next] = cost+1;
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

    rep(i, m)
    {
        cin >> x >> y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    rep1(i, n)
    {
        memset(visit, -1, sizeof(visit));
        bfs(i);
        int sum = 0;
        rep1(j, n)
        {
            sum += visit[j];
        }
        if (sum < ans)
        {
            ans = sum;
            realans = i;
        }
    }

    cout << realans;

    return 0;
}