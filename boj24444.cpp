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
vector<int> v[100003];
int visit[100003];
int depth = 1;

void bfs(int cur)
{
	queue<int> q;
	visit[cur] = depth;
	depth++;
	q.push(cur);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i];

			if (visit[next] != 0)
				continue;

			q.push({ next });
			visit[next] = depth;
			depth++;
		}
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(visit, 0, sizeof(visit));

	cin >> N >> M >> R;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i <= N; i++)
	{
		sort(v[i].begin(), v[i].end());
	}
	
	bfs(R);

	rep1(i, N)
	{
		cout << visit[i] << "\n";
	}

	return 0;
}
