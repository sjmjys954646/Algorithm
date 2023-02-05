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

int N, H, M;
int arr[32][11];
int arrtmp[32][11];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 0,1,0,0 };
vector<pair<int, int>> posV;
vector<int> selected;
int ans = INF;

void posCheck()
{
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (arr[i][j] == 2 || arr[i][j] == 3)
				continue;

			if (arr[i][j] == 1 && arr[i][j + 1] == 1)
			{
				posV.push_back({ i,j });
			}
		}
	}
}

int dfs(int startY, int startX, int befY)
{
	if (startY == H + 1)
		return startX;

	int cur = arrtmp[startY][startX];

	if(befY != startY)
		return dfs(startY + dy[cur], startX + dx[cur], startY);
	else
		return dfs(startY + dy[1], startX + dx[1], startY);
}


void mapMake()
{
	copy(&arr[0][0], &arr[0][0] + 32 * 11, &arrtmp[0][0]);
	for (int i = 0; i < selected.size(); i++)
	{
		int p = selected[i];
		if (arrtmp[posV[p].first][posV[p].second] != 1)
			return;

		arrtmp[posV[p].first][posV[p].second] = 2;
		arrtmp[posV[p].first][posV[p].second + 1] = 3;
	}


	bool pos = true;
	for (int i = 1; i <= N; i++)
	{
		if (i != dfs(0, i, 0))
			pos = false;

		if (!pos)
			break;
	}

	if (pos)
		ans = min(ans, (int)selected.size());
}

void select(int cur, int index, int num)
{
	if (index == num)
	{
		//계산함수
		mapMake();

		return;
	}

	for (int i = cur; i < posV.size(); i++)
	{
		selected.push_back(i);
		select(i + 1, index + 1, num);
		selected.pop_back();
	}
}



int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	int a, b;

	cin >> N >> M >> H;

	fill(arr[0], arr[32], 1);

	for (int i = 1; i <= N; i++)
	{
		arr[H + 1][i] = -1;
	}
    
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		arr[a][b] = 2;
		arr[a][b + 1] = 3;
	}

	posCheck();

	mapMake();
	select(0, 0, 1);
	select(0, 0, 2);
	select(0, 0, 3);

	if (ans == INF)
		cout << -1;
	else
		cout << ans;

	return 0;
}
