#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stdio.h>
#include <string>
#include <math.h>
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		return a.first < b.first ? true : false;
	}
	else
	{
		return a.second < b.second ? true : false;
	}
}

int main()
{
	int num;
	int sum = 0;
	pair<int, int> tmp;

	cin >> num;

	vector<pair<int, int> > arr(num);

	for (int i = 0; i < num; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < num; i++)
	{
		if (i == 0)
		{
			sum += 1;
			tmp = arr[i];
			continue;
		}

		if (tmp.second <= arr[i].first)
		{
			tmp = arr[i];
			sum += 1;
		}
	}

	cout << sum;

	return 0;
}