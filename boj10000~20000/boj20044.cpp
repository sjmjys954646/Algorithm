#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <string>

using namespace std;

int N;
vector<int> v;

int main()
{
	int tmp;

	cin >> N;

	for (int i = 0; i < 2 * N; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	
	sort(v.begin(), v.end());

	int ans = 98654321;

	for (int i = 0; i < N; i++)
	{
		ans = min(ans, v[i] + v[2 * N - i - 1]);
	}

	cout << ans;

	return 0;
}
