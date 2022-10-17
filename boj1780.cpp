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

int board[2200][2200];
int first = 0;//-1
int second = 0;//0
int third = 0;//1

void Cut(int a, int b,int N)
{
	bool check = true;
	int tmp = board[a][b];
	for (int i = a; i < a+N; i++)
	{
		for (int j = b; j < b+N; j++)
		{
			if (tmp != board[i][j])
				check = false;
		}
	}

	if (check)
	{
		if (tmp == 0)
		{
			second += 1;
		}
		else if (tmp == 1)
		{

			third += 1;
		}
		else if(tmp == -1)
		{
			first += 1;
		}	
		return;
	}
	else
	{
		int X[3] = { 0,N / 3,2 * N / 3 };

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				Cut(a+X[i],b+ X[j], N / 3);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int num;

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			cin >> board[i][j];
		}
	}

	Cut(0,0,num);

	cout << first << "\n" << second << "\n" << third;
	return 0;
}

