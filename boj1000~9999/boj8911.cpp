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

int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	int testcase;

	cin >> testcase;

	while (testcase--)
	{
		int maxX = 0;
		int maxY = 0;
		int minX = 0;
		int minY = 0;

		int dir = 0;

		string tmp;
		cin >> tmp;

		int curX = 0;
		int curY = 0;
		for (int i = 0; i < tmp.size(); i++)
		{
			char cur = tmp[i];
			if (cur == 'F')
			{
				curY = curY + dY[dir];
				curX = curX + dX[dir];

				maxX = max(maxX, curX);
				maxY = max(maxY, curY);
				minX = min(minX, curX);
				minY = min(minY, curY);
			}
			else if (cur == 'B')
			{
				curY = curY - dY[dir];
				curX = curX - dX[dir];

				maxX = max(maxX, curX);
				maxY = max(maxY, curY);
				minX = min(minX, curX);
				minY = min(minY, curY);
			}
			else if (cur == 'L')
			{
				dir -= 1;
				if (dir == -1)
					dir = 3;
			}
			else if (cur == 'R')
			{
				dir += 1;
				if (dir == 4)
					dir = 0;
			}
		}
		cout << (maxX + abs(minX)) * (maxY + abs(minY)) << "\n";
	}

	return 0;
}
