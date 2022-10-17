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

const int INF = 987654321;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	bool cycle = false;
	vector<pair<int, int> > graph[502];
	long long dist[502];

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		graph[v1].push_back({ v2,w });
	}

	//memset(dist, INF, sizeof(dist));
	fill(dist, dist + 502, INF);

	dist[1] = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (auto k : graph[j])
			{
				if(dist[j]!=INF && dist[k.first] > k.second + dist[j])
				{
					dist[k.first] = k.second + dist[j];
					if (i == N)
						cycle = true;
				}			
			}
		}
	}

	if (cycle)
		cout << "-1\n";
	else
	{
		for (int i = 2; i <= N; i++)
		{
			if (dist[i] == INF)
				cout << "-1\n";
			else
				cout << dist[i]<<"\n";
		}
	}


	return 0;
}
