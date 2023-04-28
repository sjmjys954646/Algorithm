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
int arr[502][502];
int indegree[502];
int ans[502];
int cycle = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;
	int tmp;
	int a, b;

	cin >> testcase;

	while (testcase--)
	{
		/* initialization */
		memset(arr, 0, sizeof(arr));
		memset(indegree, 0, sizeof(indegree));
		cycle = 0;
		/* initialization */

		cin >> N;

		vector<int> seq;
		
		for (int i = 0; i < N; i++)
		{
			cin >> tmp;
			seq.push_back(tmp);
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < i; j++)
			{
				arr[seq[j]][seq[i]] = 1;
				indegree[seq[i]]++;
			}
		}

		cin >> M;

		while (M--)
		{
			cin >> a >> b;
			if (arr[a][b]==1)
			{
				indegree[b]--;
				indegree[a]++;
			}
			else
			{
				indegree[a]--;
				indegree[b]++;
			}
			swap(arr[a][b],arr[b][a]);
		}

		queue<int> q;
		for (int i = 1; i <= N; i++) 
		{
			if (!indegree[i])
				q.push(i);
		}

		for (int i = 0; i < N; i++)
		{
			if (q.empty())
			{
				cycle = 1;
				break;
			}
			else if (q.size() > 1)
			{
				cycle = 2;
				break;
			}

			int here = q.front();
			ans[i] = here;
			q.pop();
			for (int j = 1; j <= N; j++) 
			{
				if (arr[here][j]) {
					indegree[j]--;
					if (!indegree[j])
						q.push(j);
				}
			}
		}

		if (cycle == 1)
			cout << "IMPOSSIBLE\n";
		else if (cycle == 2)
			cout << "?\n";
		else 
		{
			for (int i = 0; i < N; i++)
				cout << ans[i]<<" ";
			cout << "\n";
		}



	}
	
	return 0;
}