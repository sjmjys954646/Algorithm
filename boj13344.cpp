#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

int N;
int M;
vector<int> arr[50010];
vector<pair<int, int>> order;
int indegree[50010];
int par[50010];
bool check = true;

int find(int a)
{
	if(a== par[a])
		return a;
	return par[a] = find(par[a]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
	{
		par[b] = a;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
;
	int a, b;
	char tmp;
	int count = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		par[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> a >> tmp >> b;
		if (tmp == '=')
		{
			int p = min(a, b);
			p == a ? merge(a, b) : merge(b, a);
		}
		else
		{
			order.push_back({ a,b });
		}
	}

	for (int i = 0; i < order.size(); i++)
	{
		a = order[i].first;
		b = order[i].second;

		a = find(a);
		b = find(b);

		vector<int>::iterator it = find(arr[a].begin(), arr[a].end(), b);
		if (it != arr[a].end())
			continue;

		arr[a].push_back(b);
		indegree[b]++;
	}

	queue<int> q;
	for (int i = 0; i < N; i++)
	{
		if (i != par[i])
			continue;

		count++;

		if (!indegree[i])
			q.push(i);
	}

	for (int i = 0; i < count; i++)
	{
		if (q.empty())
		{
			check = false;
			break;
		}
		int here = q.front();
		q.pop();
		for (int j = 0; j < arr[here].size(); j++)
		{
			int next = arr[here][j];
			indegree[next]--;
			if (!indegree[next])
				q.push(next);
		}
	}
	if(check)
		cout << "consistent";
	else
		cout << "inconsistent";

	return 0;
}