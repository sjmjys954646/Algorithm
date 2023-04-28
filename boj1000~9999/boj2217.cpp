#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stdio.h>
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

int main()
{
	int num;
	vector<int> arr;
	int temp;
	int max = 0;

	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end(),greater<int>());

	for (int i = 1; i <= num; i++)
	{
		max = Max(max, arr[i - 1] * i);
	}

	
	cout << max;


	return 0;
}

