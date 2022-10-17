#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stdio.h>
#include <string>
#include<string.h>
#include <math.h>
#include <map>
#include <queue>
#include <stdlib.h>
#define X first
#define Y second
using namespace std;

struct graph
{
	int node, cost;
	bool operator <(const graph t) const { return cost > t.cost; }
};

int V, E, Ftogo, Stogo;
const int INF = 987654321;
vector<graph> a[802];
vector< long long> dist;

long long Dijkstra(int start, int fin)
{
	fill(dist.begin(), dist.end(), INF);
	priority_queue<graph> pq;
	pq.push({ start,0 });
	dist[start] = 0;

	while (!pq.empty())
	{
		int node = pq.top().node;
		int cost = pq.top().cost;

		pq.pop();

		if (dist[node] < cost)
			continue;

		for (auto k : a[node])
		{
			int nextnode = k.node;
			int nextcost = k.cost + cost;

			if (dist[nextnode] > nextcost)
			{
				dist[nextnode] = nextcost;
				pq.push({ nextnode,nextcost });
			}
		}
	}
	return dist[fin];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		a[v1].push_back({ v2,w });
		a[v2].push_back({ v1,w });
	}
	dist.resize(V + 1);

	cin >> Ftogo >> Stogo;

	long long a = Dijkstra(1, Ftogo);
	long long b = Dijkstra(Ftogo, Stogo);
	long long e = Dijkstra(Stogo, V);
	long long c = Dijkstra(1, Stogo);
	long long d = Dijkstra(Ftogo, V);

	long long ta = 0;
	long long tb = 0;

	if (a == INF || b == INF || e == INF)
	{
		ta = INF;
	}
	else if (c == INF || b == INF || d == INF)
	{
		tb = INF;
	}

	ta == INF ? ta = INF : ta = a + b + e;
	tb == INF ? tb = INF : tb = c + b + d;

	if (min(ta, tb) == INF)
		cout << -1;
	else
		cout << min(ta, tb);


	return 0;
}
