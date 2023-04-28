#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <string>

using namespace std;

vector<pair<int, int>> arr[10002];
int cache[10002];

int main()
{
	int N, D;

	cin >> N >> D;

	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		arr[a].push_back({ b,c });
	}

	for (int i = 1; i <= D; i++)
		cache[i] = 986543210;
	
	for (int i = 0; i < D; i++)
	{
		cache[i + 1] = min(cache[i + 1],cache[i] + 1);

		for (int j = 0; j < arr[i].size(); j++)
		{
			cache[arr[i][j].first] = min(cache[arr[i][j].first], cache[i] + arr[i][j].second);
		}
	}

	cout << cache[D];

	return 0;
}