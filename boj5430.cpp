#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <deque>
#include <stdio.h>
#include <string>
#include <math.h>
#include <map>
#include <stack>
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

int main()
{
	int testcase;

	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		deque<int> dq;
		string function;
		int length;
		bool front = true;
		char ch;
		bool check = true;
		string arr;
		
		cin >> function;
		cin >> length;

		cin >> ch;
		for (int j = 0; j < length; j++)
		{
			int tmp;
			cin >> tmp;
			dq.push_back(tmp);
			cin >> ch;
		}
		if (length == 0)
			cin >> ch;

		for (int j = 0; j < function.size(); j++)
		{
			if (function[j] == 'R')
			{
				if (front)
					front = false;
				else
					front = true;
			}
			else
			{
				if (dq.empty())
				{
					check = false;
					break;
				}

				if (front)
					dq.pop_front();
				else
					dq.pop_back();
			}
		}

		if (!check)
		{
			cout << "error\n";
		}
		else
		{
			cout << '[';
			if (front)
			{
				if (!dq.empty())
				{
					cout << dq.front();
					dq.pop_front();
				}
				while (!dq.empty())
				{
					cout << ',';
					cout << dq.front();
					dq.pop_front();
				}
			}
			else
			{
				if (!dq.empty())
				{
					cout << dq.back();
					dq.pop_back();
				}
				while (!dq.empty())
				{
					cout << ',';
					cout << dq.back();
					dq.pop_back();
				}
			}
			cout << ']' << '\n';
		}
	}

	return 0;
}