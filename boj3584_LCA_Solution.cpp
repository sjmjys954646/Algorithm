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

int depth[10002];
int ac[10002][20];
vector<int> graph[10002];
int indegree[10002];
int maxhi;

void getTree(int here, int par)
{
	depth[here] = depth[par] + 1;
	ac[here][0] = par;

	for (int i = 1; i <= maxhi; i++)
	{
		int tmp = ac[here][i - 1];
		ac[here][i] = ac[tmp][i - 1];
	}

	for(int i = 0; i < graph[here].size(); i++)
	{
		int there = graph[here][i];
		if (there != par)
			getTree(there, here);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;

	cin >> testcase;

	while (testcase--)
	{
		int N;
		int N1, N2;
		int A, B;

		maxhi = (int)floor(log2(10002));

		memset(depth, -1, sizeof(depth));
		memset(ac, 0, sizeof(ac));
		memset(indegree, 0, sizeof(indegree));
		for (int i = 0; i < 10002; i++)
		{
			graph[i].clear();
		}

		cin >> N;

		for (int i = 1; i < N ; i++)
		{
			cin >> N1 >> N2;
			graph[N1].push_back(N2);
			graph[N2].push_back(N1);
			indegree[N2]++;
		}

		int root = 0;
		for (int i = 1; i < N + 1; i++)
		{
			if (indegree[i] == 0)
			{
				root = i;
				break;
			}
		}


		getTree(root, 0);

		cin >> A >> B;

		if (depth[A] != depth[B])
		{
			if (depth[A] > depth[B])
				swap(A, B);

			for (int i = maxhi; i >= 0; i--)
			{
				if (depth[A] <= depth[ac[B][i]])
				{
					B = ac[B][i];
				}
			}
		}

		int ans = A;
		if (A != B) 	
		{
			for (int i = maxhi; i >= 0; i--)
			{
				if (ac[A][i] != ac[B][i])
				{
					A = ac[A][i];
					B = ac[B][i];
				}
				ans = ac[A][i];
			}
		}

		cout << ans<<"\n";

	}


	return 0;
}