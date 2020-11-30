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

int par[10002];

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
		vector<int> vec1;
		vector<int> vec2;
		int ans = 99999999;

		memset(par, -1, sizeof(par));

		cin >> N;

		for (int i = 0; i < N - 1; i++)
		{
			cin >> N1 >> N2;
			par[N2] = N1;
		}
		cin >> A >> B;

		int tmp = A;
		vec1.push_back(tmp);
		while (par[tmp] != -1)
		{
			vec1.push_back(par[tmp]);
			tmp = par[tmp];
		}
		tmp = B;
		vec2.push_back(tmp);
		while (par[tmp] != -1)
		{
			vec2.push_back(par[tmp]);
			tmp = par[tmp];
		}

		for (int i = 0; i < vec1.size(); i++)
		{
			int cur = vec1[i];
			vector<int>::iterator it;
			it = find(vec2.begin(), vec2.end(), cur);
			if (it != vec2.end())
			{
				int index = 0;
				while (*it != vec2[index])
				{
					index++;
				}
				ans = min(ans, index);
			}
			else
			{
				continue;
			}

		}
		cout << vec2[ans] << "\n";
	}


	return 0;
}