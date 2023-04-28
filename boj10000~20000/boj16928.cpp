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
#include <stack>
#include <cstring>
#include <list>
#include <set>
#include <string.h>
#include <map>
#include <limits.h>
#include <stdlib.h>
#include <typeinfo>
#include <cmath>

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


int N, M, R;
int visit[120];
int pos[120];

void bfs(int cur)
{
	queue<int> q;
	visit[cur] = 1;
	q.push(cur);

	while (!q.empty())
	{
		int c = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++)
		{
			int next = c + i;

			if (next > 100)
				continue;

			if (pos[next] != 0)
				next = pos[next];

			if (visit[next] != -1)
				continue;

			q.push(next);
			visit[next] = visit[c] + 1;
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(visit, -1, sizeof(visit));

	cin >> N >> M;

	for (int i = 0; i < N + M; i++)
	{
		int a, b;
		cin >> a >> b;
		pos[a] = b;
	}

	bfs(1);

	cout << visit[100] - 1;

	return 0;
}
