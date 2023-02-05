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

int arr[1002];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	string tmp;
	cin >> tmp;

	for (int i = 1; i <= tmp.size(); i++)
	{
		if (tmp[i - 1] == 'Y')
			arr[i] = 1;
		else
			arr[i] = -1;
	}

	int ans = 0;
	for (int i = 1; i <= tmp.size(); i++)
	{
		if (arr[i] == 1)
		{
			ans++;
			for (int j = i; j <= tmp.size();)
			{
				arr[j] *= -1;
				j += i;
			}
		}
	}

	cout << ans;

	return 0;
}
