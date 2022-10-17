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

int c[202][402];
int f[202][402];
int d[202];
int a[202];
int b[202];
vector<int> arr[402];
int N, M;
int cap;

int maxFlow(int source, int sink)
{
	memset(f, 0, sizeof(f));
	int ans = 0;

	while (1)
	{
		memset(d, -1, sizeof(d));
		queue<int> q;
		q.push(source);

		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			for (int i = 0; i < arr[cur].size(); i++)
			{
				int next = arr[cur][i];
				if (c[cur][next] - f[cur][next] > 0 && d[next] == -1)
				{
					d[next] = cur;
					q.push(next);
				}
			}
		}

		if (d[sink] == -1)
			break;

		int flow = INF;
		for (int i = sink; i != source; i = d[i])
		{
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}

		for (int i = sink; i != source; i = d[i])
		{
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}

		ans += flow;

	}

	return ans;
}

int dfs(int x) 
{
	d[x] = 1;
	for (int i = 0; i < arr[x].size(); i++)
	{
		int p = arr[x][i];

		if (b[p] == -1 || !d[b[p]] && dfs(b[p]))
		{
			a[x] = p;
			b[p] = x;
			return 1;
		}

	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int f, g;

	for (int i = 1; i <= N; i++)
	{
		cin >> f;

		for (int j = 0; j < f; j++)
		{
			cin >> g;

			arr[i].push_back(g);
		}
	}

	memset(a, -1, sizeof(a));
	memset(b, -1, sizeof(b));

	int cnt = 0; 
	for (int i = 1; i <= N; i++) 
	{
		if (a[i] != -1)
			continue;

		fill(d, d + 202, 0);
		if (dfs(i)) 
			cnt++;
	}
	
	cout<<cnt;

	return 0;
}