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

const int INF = 1e9;

int testcase;

int tmp;
int graph[303][303][303];
int N, M, K, Q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> graph[i][j][0];
            if (graph[i][j][0] == 0 && i!=j) 
            {
                graph[i][j][0] = INF;
            }
        }
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                graph[i][j][k] = min(graph[i][j][k - 1], graph[i][k][k - 1] + graph[k][j][k - 1]);
            }
        }
    }

    for (int i = 0; i < Q; i++)
    {
        int a, b, c;
        cin >> c >> a >> b;
        if (graph[a][b][c-1] == INF)
            cout << -1 << "\n";
        else
            cout << graph[a][b][c-1]<<"\n";
    }
   

    return 0;
}
