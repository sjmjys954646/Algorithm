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

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	string tmp;
	int N;
	cin >> N;
	cin >> tmp;

	vector<int> v;
	int sum = 1;
	char cur = tmp[0];
	for (int i = 1; i < N; i++)
	{
		if (cur != tmp[i])
		{
			v.push_back(sum);
			cur = tmp[i];
			sum = 1;
		}
		else
			sum++;
	}
	v.push_back(sum);

	if (v.size() == 0)
		cout << 0;
	else
	{
		int ans = 0;
		for (int i = 0; i < v.size() - 1; i++)
		{
			ans = max(ans, 2*min(v[i],v[i+1]));
		}
		cout << ans;
	}

	return 0;
}
