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

class Info
{
public:
	int des;
	int cost;
	int time;
	Info(int a, int b, int c) : des(a), cost(b), time(c) {};
};

struct cmp
{
	bool operator()(Info x, Info y)
	{
		return x.time > y.time;
	}
};


int N, M, K;
vector<Info> graph[102];
int cache[102][10002];


int dijkstra()
{
	int ret = INF;
	priority_queue<Info,vector<Info>,cmp> pq;
	pq.push(Info(1, 0, 0));
	memset(cache, -1, sizeof(cache));
	cache[1][0] = 1;
	pq.push(Info(1, 0, 0));

	while (!pq.empty())
	{
		Info cur = pq.top();
		pq.pop();

		if (cur.time > cache[cur.des][cur.cost] || cur.cost > M)
			continue;

		for (int i = 0; i < graph[cur.des].size(); i++)
		{
			Info tmp = graph[cur.des][i];
			int tmpCost = tmp.cost + cur.cost;
			if ((cache[tmp.des][tmpCost] == -1 || cache[tmp.des][tmpCost] > cur.time + tmp.time)
				&& cur.cost + tmp.cost <= M)
			{
				cache[tmp.des][tmpCost] = cur.time + tmp.time;
				pq.push(Info(tmp.des, tmpCost, cur.time + tmp.time));
			}

		}
	}
	for (int i = 0; i <= M; i++)
	{
		if (cache[N][i] != -1 && ret > cache[N][i])
			ret = cache[N][i];
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int Testcase;

	cin >> Testcase;

	while (Testcase--)
	{
		for (int i = 0; i < 102; i++)
		{
			graph[i].clear();
		}

		cin >> N >> M >> K;

		for (int i = 0; i < K; i++)
		{
			int u1, u2, t, c;
			cin >> u1 >> u2 >> t >> c;
			graph[u1].push_back(Info(u2,t,c));
		}

		int tmp = dijkstra();
		if (tmp == INF)
			cout << "Poor KCM\n";
		else
			cout << tmp << "\n";
	}

	return 0;
}