#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <string>

using namespace std;

int cache[100002];

int main()
{
	int N;
	int tmp;
	int ans = 1;

	cin >> N;

	cache[0] = 1;
	cin >> tmp;
	for (int i = 1; i < N; i++)
	{
		cin >> tmp;
		if (tmp > cache[i - 1])
			cache[i] = cache[i - 1] + 1;
		else
			cache[i] = min(cache[i - 1], tmp);
		ans = max(cache[i], ans);
	}


	cout << ans;
	
	return 0;
}