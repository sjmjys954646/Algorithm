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

int N, M;
vector<int> arr[20002];
bool finished[20002]; // scc가 만들어됬는지
stack<int> S;
int num = 0;
int sccN = 0;
int visited[20002]; // 방문 번호
int scc[20002];
bool check;

int dfs(int start)
{
    visited[start] = ++num;
    S.push(start);
    int ret = visited[start];

    for (int next : arr[start])
    {
        if (!visited[next])
            ret = min(ret, dfs(next));
        else if (!finished[next])
            ret = min(ret, visited[next]);
    }

    if (ret == visited[start])
    {
        while (true)
        {
            int tmp = S.top();
            S.pop();
            scc[tmp] = sccN;
            finished[tmp] = true;
            if (tmp == start)
                break;
        }
        sccN++;
    }

    return ret;
}

int main()
{
    freopen("input.txt", "r", stdin);
    memset(finished, 0, sizeof(finished));
    memset(visited, 0, sizeof(visited));

    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
        int A, B;
        scanf("%d %d", &A, &B);

        A = (A < 0 ? -(A + 1) * 2 : A * 2 - 1);
        // -2 -> 2, 2 -> 3, -3 -> 4 , 3 -> 5
        B = (B < 0 ? -(B + 1) * 2 : B * 2 - 1);

        arr[A % 2 ? A - 1 : A + 1].pb(B);
        arr[B % 2 ? B - 1 : B + 1].pb(A);
    }

    rep(i, N * 2)
    {
        if (visited[i] == 0)
            dfs(i);
    }

    for (int i = 0; i < N; i++)
    {
        if (scc[i * 2] == scc[i * 2 + 1])
        {
            check = true;
        }
    }

    if (check)
        cout << 0;
    else
        cout << 1;

    return 0;
}