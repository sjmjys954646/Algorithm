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

vi graph[52];
int N;
int A, B;
vi ans;
int arr[52];
int visited[52];

void bfs(int start)
{
    queue<pair<int, int>> q;
    q.push({start, 1});
    visited[start] = 1;

    while (!q.empty())
    {
        int des = q.front().F;
        int cost = q.front().S;
        q.pop();

        for (int i = 0; i < graph[des].size(); i++)
        {
            int next = graph[des][i];
            if (!visited[next])
            {

                visited[next] = cost + 1;
                q.push({next, cost + 1});
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    scanf("%d", &N);

    rep1(i, N)
    {
        arr[i] = INF;
    }

    while (true)
    {
        scanf("%d %d", &A, &B);
        if (A == -1 && B == -1)
            break;

        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    rep1(i, N)
    {
        memset(visited, 0, sizeof(visited));
        bfs(i);
        int m = -1;
        rep1(i, N)
        {
            m = max(visited[i], m);
        }
        arr[i] = m;
    }

    int mini = INF;
    rep1(i, N)
    {
        mini = min(mini, arr[i]);
    }
    rep1(i, N)
    {
        if (arr[i] == mini)
            ans.push_back(i);
    }
    sort(ans.begin(), ans.end());

    printf("%d %d\n", mini - 1, ans.size());
    rep(i, ans.size())
    {
        printf("%d ", ans[i]);
    }
    return 0;
}