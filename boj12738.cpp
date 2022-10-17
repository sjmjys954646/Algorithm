#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <cstring>

using namespace std;


int main()
{
	int num;
	int arr[1000020];
	int ans = 0;
  

	vector<long long> vec;

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}

	vec.push_back(-9876543210);
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

	cout << vec.size()-1 <<"\n";

	return 0;
}
