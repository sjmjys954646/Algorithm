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

vector<int> v;
int N, M;
int tmp;
vector<int> selected;
int visited[10];

void dfs(int idx)
{
	if (idx == M)
	{
		for (auto i : selected)
			cout << i << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (visited[i])
			continue;

		selected.push_back(v[i]);
		visited[i] = 1;
		dfs(idx + 1);
		selected.pop_back();
		visited[i] = 0;
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	dfs(0);

	return 0;
}
