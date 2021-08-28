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

int arr[104];
int visited[104];
vector<int> ans;

void dfs(int root, int start)
{
    visited[start] = 1;

    int next = arr[start];

    if (root == next)
    {
        ans.pb(root);
        return;
    }

    if (!visited[next])
        dfs(root, next);
}

int main()
{
    freopen("input.txt", "r", stdin);

    int N;

    scanf("%d", &N);

    rep1(i, N)
    {
        scanf("%d", &arr[i]);
    }

    rep1(i, N)
    {
        memset(visited, 0, sizeof(visited));
        dfs(i, i);
    }

    printf("%d\n", ans.size());

    rep(i, ans.size())
    {
        printf("%d\n", ans[i]);
    }

    return 0;
}