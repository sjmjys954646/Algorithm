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
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

int main()
{
	deque<int> dq;
	int num;
	int testcase;
	int sum = 0;

	cin >> num >> testcase;

	for (int i = 1; i <= num; i++)
	{
		dq.push_back(i);
	}
	
	for (int i = 0; i < testcase; i++)
	{
		int index;
		cin >> index;

		int pos = 1;


		for (auto it = dq.begin(); it != dq.end(); it++)
		{
			if (*it == index)
				break;
			pos++;

		}
		int left = pos - 1;
		int right = dq.size() - pos + 1;

		if (left < right)
		{
			for (int j = 1; j <= left; j++)
			{
				int tmp = dq.front();
				dq.pop_front();
				dq.push_back(tmp);
				sum++;
			}
			dq.pop_front();
		}
		else
		{
			for (int j = 1; j <= right; j++)
			{
				int tmp = dq.back();
				dq.pop_back();
				dq.push_front(tmp);
				sum++;
			}
			dq.pop_front();
		}


	}
	cout << sum;

	return 0;
}