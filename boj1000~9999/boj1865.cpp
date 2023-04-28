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

vector< vector< pair<int, int > > > graph;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int Testcase;

	cin >> Testcase;

	while (Testcase--)
	{	
		int N, M, W;
		bool cycle = false;
		int dist[501];

		graph.clear();
		graph.resize(501);

		cin >> N >> M >> W;

		for (int i = 0; i < M; i++)
		{
			int u1, u2, w;
			cin >> u1 >> u2 >> w;
			graph[u1].push_back({ u2,w });
			graph[u2].push_back({ u1,w });
		}
		for (int i = 0; i < W; i++)
		{
			int u1, u2, w;
			cin >> u1 >> u2 >> w;
			graph[u1].push_back({ u2,-w });
		}

		for (int i = 2; i <= N; i++) 
            dist[i] = INF;

		for (int i = 1;i<=N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				for (auto k : graph[j])
				{
					if (dist[k.first] > k.second + dist[j])
					{
						dist[k.first] = k.second + dist[j];
						if (i == N )
							cycle = true;
					}
				}
			}
		}
		

		if (!cycle)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	
	return 0;
}