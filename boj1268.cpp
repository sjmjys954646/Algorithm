#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <assert.h>

using namespace std;

int board[5][1002];
int student;
int studentFriendSheet[1002][1002];
int studentFriend[1002];

int main()
{
	cin >> student;

	for (int i = 0; i < student; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> board[j][i];
		}
	}

	for (int g = 0; g < 5; g++)
	{
		for (int i = 0; i < student; i++)
		{
			for (int j = 0; j < student; j++)
			{
				if (i == j)
					continue;
				if (board[g][i] == board[g][j])
				{
					studentFriendSheet[i][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < student; i++)
	{
		for (int j = 0; j < student; j++)
		{
			if(studentFriendSheet[i][j] > 0)
				studentFriend[i]++;
		}
	}


	int maxi = -1;
	int ans = -1;

	for (int i = 0; i < student; i++)
	{
		if (maxi == studentFriend[i])
			continue;

		if (maxi < studentFriend[i])
		{
			maxi = studentFriend[i];
			ans = i + 1;
		}
	}
	
	cout << ans;

	return 0;
}