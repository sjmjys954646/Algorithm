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

int GCD(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int num;

	cin >> num;

	vector<int> arr;
	vector<int> ans;

	for (int i = 0; i < num; i++)
	{
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());

	int gcd = arr[1] - arr[0];

	for (int i = 2; i < num; i++)
	{
		gcd = GCD(gcd, arr[i] - arr[i - 1]);
	}

	for (int i = 2; i * i <= gcd; i++)
	{
		if (gcd % i == 0)
		{
			ans.push_back(i);
			ans.push_back(gcd / i);
		}
	}
	ans.push_back(gcd);
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	
	for (auto i = ans.begin(); i != ans.end(); i++)
	{
		cout << *i << " ";
	}
	cout << "\n";
	return 0;
}