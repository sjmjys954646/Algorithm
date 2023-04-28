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
#define X first
#define Y second
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

vector<int> graph[100002];
int check[100002];
queue<int> q;
int N, K;


void bfs(int s)
{
	q.push(s);
	check[s] = 1;

	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();

		if (tmp == K)
			break;

		for (int i = 0; i < graph[tmp].size(); i++) 
		{
			if (check[graph[tmp][i]] == 0 && graph[tmp][i] <= 100000  )
			{
				q.push(graph[tmp][i]);
				check[graph[tmp][i]] = check[tmp] + 1;
			}
		}

		//for (int i = 0; i < 30; i++)
		//{
		//	cout<< check[i]<<"\n";
		//}
		//"\n";
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	memset(check, 0, sizeof(check));

	graph[0].push_back(1);
	graph[1].push_back(2);

	for (int i = 2; i < 100001; i++)
	{
		graph[i].push_back(i - 1);
		graph[i].push_back(i + 1);
		graph[i].push_back(i * 2);
	}

	if (N < K)
	{
		bfs(N);
		cout << check[K]-1;
	}
	else if (N == K)
	{
		cout << "0";
	}
	else
	{
		cout << N - K;
	}

	return 0;
}
