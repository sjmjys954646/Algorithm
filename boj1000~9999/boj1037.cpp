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

int main()
{
	long long num;
	long long tmp;
	vector<long long> arr;
	
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> tmp;
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());

	if (num % 2 == 0)
	{
		cout << arr[0] * arr[num-1];
	}
	else
	{
		cout << arr[(num - 1) / 2] * arr[(num - 1) / 2];
	}
	return 0;
}
