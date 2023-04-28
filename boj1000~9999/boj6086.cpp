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

int c[402][402];
int f[402][402];
int d[402];
vector<int> arr[402];
int N, P;
char a, b;
int cap;

int converter(char A)
{
	if (A > 90)
		return A - 'a' + 26;
	else
		return A - 'A';
}

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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> cap;

		arr[converter(a)].push_back(converter(b));
		arr[converter(b)].push_back(converter(a));
		c[converter(a)][converter(b)] += cap;
		c[converter(b)][converter(a)] += cap;
	}
	
	cout<<maxFlow(0,25);

	return 0;
}