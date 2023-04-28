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

int cache[62][2];
int N;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N;

	cache[1][0] = 2;
	cache[1][1] = 1;

	for (int i = 2; i <= 15; i++)
	{
		cache[i][0] = 2 * (cache[i - 1][0] + cache[i - 1][1]);
		cache[i][1] = cache[i - 1][0] + cache[i - 1][1];
	}

	cout << cache[N][0];
	
	return 0;
}
