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

const int INF = 987654321;

int testcase;
int N, K;
int arr[12][12];
int dist[12][12];
int visit[12];
int ans = INF;

bool check()
{
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sum += visit[i];
    }

    if (sum == N)
        return true;
    else
        return false;
}

void loop(int v, int cur)
{
    if (check())
    {
        ans = min(cur, ans);
    }

    for (int i = 1; i <= N; i++)
    {
        if (visit[i])
            continue;

        visit[i] = 1;
        loop(i, cur + dist[v][i]);
        visit[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    K++;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j) 
                dist[i][j] = 0;
            else 
                dist[i][j] = arr[i][j];
        }
    }


    for (int k = 1; k <= N; k++) 
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++) 
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    visit[K] = 1;
    loop(K,0);

    cout << ans;

    return 0;
}