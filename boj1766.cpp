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
vector<int> arr[32010];
int indegree[32010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
;
	int a, b;

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		arr[a].push_back(b);
		indegree[b]++;
	}

	priority_queue<int> pq;
	for (int i = 1; i <= N; i++)
	{
		if (!indegree[i])
			pq.push(-i);
	}

	while (pq.size())
	{
		int here = -pq.top();
		cout << here << " ";
		pq.pop();
		for (int j = 0; j < arr[here].size(); j++)
		{
			int next = arr[here][j];
			indegree[next]--;
			if (!indegree[next])
				pq.push(-next);
		}
	}



	return 0;
}