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
	int num;
	int sum = 0;

	cin >> num;

	vector<int> arr(num);

	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	for (int i = 1; i < num; i++)
	{
		arr[i] += arr[i - 1];
		sum += arr[i];
	}

	cout << sum + arr[0];

	return 0;
}
