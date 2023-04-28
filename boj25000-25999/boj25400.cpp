#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <string>

using namespace std;

int N;


int main()
{
	cin >> N;
	int ans = 0;
	int cur = 1;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp != cur)
			ans++;
		else
			cur++;
	}
	cout << ans;
	
	return 0;
}