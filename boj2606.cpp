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
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

int infected = 0;
vector<int> graph[102];
int check[102];
int Num, N;

void dfs(int pos)
{
	infected++;
	check[pos] = 1;

	for (int i = 0; i < graph[pos].size(); i++)
	{
		int next = graph[pos][i];

		if (check[next] == 0)
			dfs(next);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> Num;
	cin >> N;

	int t1, t2;

	for (int i = 0; i < N; i++)
	{
		cin >> t1 >> t2;
		graph[t1].push_back(t2);
		graph[t2].push_back(t1);
	}
	dfs(1);

	cout << infected -1;

	return 0;
}
