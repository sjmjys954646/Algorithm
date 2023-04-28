#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stdio.h>
#include <string>
#include <math.h>
#include <map>
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;


int main()
{
	int num;
	int sum = 0;
	cin >> num;

	int arr[101];
	for (int i = 1; i < 101; i++)
	{
		if (i % 25 == 0)
		{
			arr[i] = 3;
		}
		else if (i % 5 == 0)
		{
			arr[i] = 2;
		}
		else
		{
			arr[i] = 1;
		}
	}
	num /= 5;
	for (int i = 1; i <= num; i++)
	{
		sum += arr[i];
	}
	cout << sum;
	return 0;
}