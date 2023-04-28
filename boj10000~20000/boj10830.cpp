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

int N;
long long board[5][5];
long long ansboard[5][5];
vector<int> calc;

void Multi(bool check)
{
	long long tmpboard[5][5];
	memset(tmpboard, 0, sizeof(tmpboard));

	if (check)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < N; k++)
				{
					tmpboard[i][j] += (ansboard[i][k] % 1000 * board[k][j] % 1000) % 1000;
				}

			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				ansboard[i][j] = tmpboard[i][j] % 1000;
			}
		}
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < N; k++)
				{
					tmpboard[i][j] += (ansboard[i][k] % 1000 * ansboard[k][j] % 1000) % 1000;
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				ansboard[i][j] = tmpboard[i][j] % 1000;
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long int B;

	cin >> N >> B;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
			ansboard[i][j] = board[i][j]%1000;
		}
	}

	while (B > 1)
	{
		if (B % 2 == 1)
		{
			B -= 1;
			calc.push_back(2);
		}
		calc.push_back(1);
		B /= 2;
	}

	while (!calc.empty())
	{
		if (calc.back() == 1)
		{
			Multi(false);
		}
		else
		{
			Multi(true);
		}
		calc.pop_back();
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << ansboard[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
