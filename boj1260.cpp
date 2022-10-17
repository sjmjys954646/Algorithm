#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

int V, E, start;
bool check[1001];
vector<int> graph[1001];
queue<int> q;

void dfs(int pos)
{
	cout << pos << " ";
	check[pos] = 1;
	for (int i = 0; i < graph[pos].size(); i++)
	{
		int next = graph[pos][i];
		
		if (check[next] == 0)
			dfs(next);
	}
}

void bfs(int pos)
{
	while (!q.empty())
	{
		int front = q.front();
		q.pop();

		if (check[front] == 0)
		{
			cout << front << " ";
			check[front] = 1;
		}

		for (int i = 0; i < graph[front].size(); i++)
		{
			if (check[graph[front][i]] == 0)
			{
				q.push(graph[front][i]);
			}
		}
	}
}

int main(void)
{
	int t1, t2;

	cin >> V >> E >> start;
	
	for (int i = 0; i < E; i++)
	{
		cin >> t1 >> t2;
		graph[t1].push_back(t2);
		graph[t2].push_back(t1);
	}

	for (int i = 1; i <= V; i++)
		sort(graph[i].begin(), graph[i].end());

	dfs(start);
	cout << "\n";

	fill(check, check + 1001, 0);

	q.push(start);
	bfs(start);

	return 0;
}