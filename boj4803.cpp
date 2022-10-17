#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <utility>
#include <map>
#include <cstdio>
#include <string>
using namespace std;

int visited[502];
vector<vector<int> > graph;
int tree = 0;
bool cycle = false;

void dfs(int start, int par)
{
	for (auto i : graph[start])
	{
		if (i == par)
			continue;
		int next = i;
		if (visited[next] == 0)
		{
			visited[next] = visited[par] + 1;
			dfs(next, start);
		}
		else if (visited[start] > visited[next])
		{
;			cycle = true;
		}
	}
}

int main()
{
	int t = 1;

	while (true)
	{
		memset(visited, 0, sizeof(visited));
		graph.clear();
		graph.resize(502);
		tree = 0;
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int i = 1; i <= n; i++)
		{
			if (visited[i])
				continue;
			cycle = false;
			dfs(i,0);
			if (cycle == false)
			{
				tree++;
			}
		}
		if (tree == 0)
		{
			cout << "Case " << t << ": No trees.\n";
		}
		else if (tree == 1)
		{
			cout << "Case " << t << ": There is one tree.\n";
		}
		else
		{
			cout << "Case " << t << ": A forest of "<<tree<<" trees.\n";
		}
		t++;
	}



	return 0;
}