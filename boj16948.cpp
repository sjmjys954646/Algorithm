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
int X, Y;
int t;

int graph[203][203];
int visit[203][203];
int N, M, K;

int dX[6] = { -2,-2,0,0,2,2 };
int dY[6] = { -1,1,-2,2,-1,1 };


int bfs() {
	queue<pair<int, int>> q;
	q.push({ m,n });
	visit[m][n] = 0;

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		if (y == Y && x == X)
			return visit[y][x];

		for (int i = 0; i < 6; i++) {
			int nx = x + dX[i];
			int ny = y + dY[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) 
				continue;

			if (visit[ny][nx] != -1)
				continue;

			visit[ny][nx] = visit[y][x] + 1;
			q.push({ ny,nx });
		}
	}
	return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	memset(visit, -1, sizeof(visit));

	cin >> N;

	cin >> n >> m >> X >> Y;

	cout << bfs();
   

    return 0;
}
