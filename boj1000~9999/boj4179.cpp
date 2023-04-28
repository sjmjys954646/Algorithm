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

struct unit {
	bool Fire;
	int Y;
	int X;
	int cost;
};

int arr[1002][1002];
int visited[1002][1002];
int startY, startX;
int R, C;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> R >> C;

	for (int i = 1; i <= R; i++)
	{
		string tmp;
		cin >> tmp;
		for (int j = 1; j <= C; j++)
		{
			if (tmp[j-1] == '#')
				arr[i][j] = -1;
			else if (tmp[j-1] == 'J')
			{
				startY = i;
				startX = j;
			}
			else if (tmp[j-1] == 'F')
				arr[i][j] = 1;
		}
	}
	queue<unit> q;

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (arr[i][j] == 1)
			{
				unit u = { true, i,j,0 };
				q.push(u);
			}
		}
	}

	visited[startY][startX] = 1;
	q.push({ false, startY, startX , 0 });


	int ans = INF;

	while (!q.empty())
	{
		auto tp = q.front();
		q.pop();


		if (tp.Fire == false)
		{
			if (tp.Y == 0 || tp.X == 0 || tp.Y == R + 1 || tp.X == C + 1)
			{
				ans = min(ans, tp.cost);
				break;
			}
		}

		if (tp.Fire)
		{
			for (int i = 0; i < 4; i++)
			{
				int nY = tp.Y + dy[i];
				int nX = tp.X + dx[i];

				if (nY == 0 || nX == 0 || nY == R + 1 || nX == C + 1)
					continue;

				if (arr[nY][nX] == -1 || arr[nY][nX] == 1)
					continue;

				arr[nY][nX] = 1;
				q.push({ true, nY, nX, 0});
			}
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				int nY = tp.Y + dy[i];
				int nX = tp.X + dx[i];

				if (arr[nY][nX] == -1 || arr[nY][nX] == 1)
					continue;
				if (visited[nY][nX])
					continue;

				visited[nY][nX] = 1;
				q.push({false, nY, nX, tp.cost + 1});
			}
		}

	}

	if (ans == INF)
		cout << "IMPOSSIBLE";
	else
		cout << ans;


	return 0;
}
