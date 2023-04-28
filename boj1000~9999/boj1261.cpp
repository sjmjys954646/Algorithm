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

int n, m, k;
int jump;
int ans = -1;
int x, y;
int t;

int graph[103][103];
int visit[103][103];
int N, M, K;

int dX[4] = { -1,1,0,0 };
int dY[4] = { 0,0,-1,1 };


int bfs() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visit[0][0] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dX[i];
			int ny = y + dY[i];

			if (nx < 0 || ny < 0 || nx >= M || ny >= N) 
				continue;

			if (graph[nx][ny] == 0 && visit[nx][ny] > visit[x][y]) {
				visit[nx][ny] = visit[x][y];
				q.push({ nx,ny });
			}

			if (graph[nx][ny] == 1 && visit[nx][ny] > visit[x][y] + 1) {
				visit[nx][ny] = visit[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
	return visit[M - 1][N - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visit[i][j] = INF;
        }
    }

    string tmp;
    for (int i = 0; i < M; i++) {
        cin >> tmp;
        for (int j = 0; j < N; j++)
        {
            graph[i][j] = tmp[j] - '0';
        }
    }

    cout << bfs();

    return 0;
}
