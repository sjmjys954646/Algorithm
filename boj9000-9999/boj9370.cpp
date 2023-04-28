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


int N, M, T;
int S, G, H;
const int INF = 987654321;
vector<vector<pair<int, int> > > a;
vector<int> dist;
vector<int> dest;

void Dijkstra(int start)
{
	priority_queue<pair<int,int> > pq;

	pq.push({ start,0 });
	fill(dist.begin(), dist.end(), INF);
	dist[start] = 0;

	while (!pq.empty())
	{
		int node = pq.top().X;
		int cost = -pq.top().Y;

		pq.pop();

		if (dist[node] < cost)
			continue;

		for (auto k : a[node])
		{
			int nextnode = k.X;
			int nextcost = k.Y + cost;

			if (dist[nextnode] > nextcost)
			{
				dist[nextnode] = nextcost;
				pq.push({ nextnode,-nextcost });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		dist.clear();
		dest.clear();
		a.clear();

		cin >> N >> M >> T;
		cin >> S >> G >> H;

		a.resize(N + 1);
		for (int i = 0; i < M; i++)
		{
			int v1, v2, w;
			cin >> v1 >> v2 >> w;
			a[v1].push_back({ v2,w });
			a[v2].push_back({ v1,w });
		}

		dist.resize(N + 1);

		for (int i = 0; i < T; i++)
		{
			int des;
			cin >> des;
			dest.push_back(des);
		}
		sort(dest.begin(), dest.end());

		Dijkstra(S);
		vector<int> dist1 = dist;
		int start;
		if (dist[G] < dist[H]) 
		{
			start = H; 
		}
		else 
		{ 
			start = G;
		}
		Dijkstra(start);
		for (int i = 0; i < dest.size(); i++)
		{
			int tmp = dest[i];
			if (dist1[tmp] == INF || dist[tmp] == INF)
				continue;

			if (dist1[tmp] == dist1[start] + dist[tmp])
			{
				cout << tmp << " ";
			}
		}
		cout << "\n";
	}



	return 0;
}