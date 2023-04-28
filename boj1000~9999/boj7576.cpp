#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stdio.h>
#include <string>
#include<string.h>
#include <math.h>
#include <map>
#include <queue>
#define X first
#define Y second
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

int unripen = 0;
int M, N;
int box[1001][1001];
int posX[4] = { 1,0,-1,0 };
int posY[4] = { 0,1,0,-1 };
queue < pair<int, int> > q;


bool isCheck()
{
	int total = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (box[i][j] == 1)
				total++;
		}
	}

	if (total == M * N - unripen)
		return true;
	else
		return false;
}

int BFS()
{
	int day = 0;

	if (q.empty())
		return -1;

	while (!q.empty())
	{
		int cur = q.size();
		for (int i = 0; i < cur; i++)
		{
			int qY = q.front().X;
			int qX = q.front().Y;

			for (int k = 0; k < 4; k++)
			{
				if (box[qY + posY[k]][qX + posX[k]] != 0)
					continue;

				if (qY + posY[k] < 0 || qY + posY[k] >= N ||
					qX + posX[k] < 0 || qX + posX[k] >= M)
					continue;

				box[qY + posY[k]][qX + posX[k]] = 1;
				q.push({ qY + posY[k],qX + posX[k] });
			}
			
			q.pop();

			if (q.size() == 0 && isCheck())
				return day;

			else if (q.size() == 0 && isCheck() == false)
				return -1;

		}

		
		day++;

	
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> box[i][j];

			if (box[i][j] == 1)
			{
				q.push({ i,j });
			}
			else if (box[i][j] == -1)
			{
				unripen++;
			}
		}
	}
	
	if (q.size() == M * N - unripen)
		cout << "0";
	else
		cout << BFS();

	return 0;
}
