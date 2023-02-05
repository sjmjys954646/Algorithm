#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <string>
#include <cmath>
#include <map>
#include <stack>
#include <string.h>
using namespace std;

vector<pair<int, int>> v;
int cache[10001];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	int N, X;

	cin >> N >> X;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	cache[0] = 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = X; j > 0; j--)
		{
			for (int k = 1; k <= v[i].second; k++)
			{
				int cur = k * v[i].first;

				if (j < cur)
					break;

				cache[j] += cache[j - cur];
			}
		}
	}

	cout << cache[X];
	
	return 0;
}
