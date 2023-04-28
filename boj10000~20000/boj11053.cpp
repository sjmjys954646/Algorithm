#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a < b ? b : a;
}

int main()
{
	int num;
	int arr[1002];
	int ans = 0;

	vector<int> vec;

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}

	vec.push_back(-1);
	for (int i = 0; i < num; i++)
	{
		if (vec.back() < arr[i])
		{
			vec.push_back(arr[i]);
			ans++;
		}
		else
		{
			auto it = lower_bound(vec.begin(), vec.end(), arr[i]);
			*it = arr[i];
		}
	}

	cout << vec.size() - 1;

	return 0;
}
