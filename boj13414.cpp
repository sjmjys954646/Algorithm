#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <string>
#include <cmath>
#include <map>
#include <stack>
#include <sstream>
#include <string.h>
#include <queue>
using namespace std;

const int INF = 987654321;

string ans[500002];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	queue<string> q;
	map<string, int> m;

	int K, L;
	cin >> K >> L;

	for(int i = 0;i<L;i++)
	{
		string tmp;
		cin >> tmp;
		q.push(tmp);
	}

	int idx = 1;
	while (!q.empty())
	{
		string p = q.front();
		q.pop();

		m[p] = idx;
		idx++;
	}

	for (auto it = m.begin(); it != m.end(); it++)
	{
		ans[it->second] = it->first;
	}

	int sum = 0;
	idx = 1;
	while (true)
	{
		if (idx > L)
			break;

		if (ans[idx].size()!=0)
		{
			cout << ans[idx] << "\n";
			sum++;

			if (sum == K)
				break;
		}

		idx++;
	}


	return 0;
}
