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
#include <stack>
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

int Count;
int N;
int col[18];

bool isPoss(int k)
{
	for (int i = 0; i < k; i++)
	{
		if (col[i] == col[k])
		{
			return false;
		}

		if (abs(col[i] - col[k]) == abs(i - k))
		{
			return false;
		}
	}
	return true;
}

void dfs(int row)
{
	if (row == N - 1)
	{
		Count++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		col[row+1] = i;
		if (isPoss(row + 1))
		{
			dfs(row + 1);
		}
	}
}




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	Count = 0;
	dfs(-1);
	cout << Count;

	return 0;
}