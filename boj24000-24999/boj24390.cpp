#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <string>

using namespace std;

bool press = false;

int cache[100000][2];
// 0 조리중이 아닐때 1 조리중일때


int main()
{

	string tmp;
	int s = 0;
	int ans = 0;

	cin >> tmp;

	s += (tmp[0] - '0') * 600;
	s += (tmp[1] - '0') * 60;
	s += (tmp[3] - '0') * 10;
	s += (tmp[4] - '0');


	for (int i = 0; i <= s; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cache[i][j] = 986543210;
		}
	}

	cache[0][0] = 0;

	for (int i = 0; i <= s; i++)
	{
		if (i == 0)
		{
			cache[i + 30][1] = min(cache[i + 30][1] ,cache[i][0] + 1);

		}
		else
		{
			cache[i][1] = min(cache[i][1],cache[i][0] + 1);
			cache[i + 30][1] = min(cache[i + 30][1], cache[i][1] + 1);
		}
		cache[i + 10][0] = min(cache[i + 10][0],cache[i][0] + 1);
		cache[i + 10][1] = min(cache[i + 10][1], cache[i][1] + 1);
		cache[i + 60][0] = min(cache[i + 60][0], cache[i][0] + 1);
		cache[i + 60][1] = min(cache[i + 60][1], cache[i][1] + 1);
		cache[i + 600][0] = min(cache[i + 600][0], cache[i][0] + 1);
		cache[i + 600][1] = min(cache[i + 600][1], cache[i][1] + 1);

	}

	cout << min(cache[s][0] + 1,cache[s][1]);

	return 0;
}
