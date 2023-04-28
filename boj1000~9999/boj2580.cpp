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

int board[9][9];
vector<pair<int, int> > blank;
bool fin;

int makeA(int a)
{
	if (0 <= a && a < 3)
		return 0;
	else if (3 <= a && a < 6)
		return 3;
	else
		return 6;
}

bool judge(pair<int, int> bl)
{
	for (int i = 0; i < 9; i++)
	{
		if (i != bl.second && board[bl.first][i] == board[bl.first][bl.second])
		{
			return false;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (i != bl.first && board[i][bl.second] == board[bl.first][bl.second])
		{
			return false;
		}
	}

	int a, b;
	a = makeA(bl.first);
	b = makeA(bl.second);

	for (int i = a; i < a + 3; i++)
	{
		for (int j = b; j < b + 3; j++)
		{
			if (i != bl.first && j != bl.second && board[i][j] == board[bl.first][bl.second])
			{
				return false;
			}
		}
	}

	return true;

}

void sudoku(int &num)
{
	if (num == blank.size())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
		
		fin = true;
		return;

	}
	
	for (int i = 1; i < 10; i++)
	{
		board[blank[num].first][blank[num].second] = i;
		if (judge(blank[num]))
		{
			sudoku(++num);
		}
		if (fin == true)
			return;
	}

	board[blank[num].first][blank[num].second] = 0;
	num--;
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num = 0;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == 0)
				blank.push_back({ i,j });
		}
	}

	sudoku(num);


	return 0;
}