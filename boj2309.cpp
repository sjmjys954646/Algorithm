#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;

const int INF = 987654321;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> arr;
	int sum = 0;

	arr.resize(9);

	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	sum -= 100;
	sort(arr.begin(), arr.end());

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (arr[i] + arr[j] == sum)
			{
				arr[i] = -1;
				arr[j] = -1;
				break;
			}
		}
		if (arr[i] == -1)
			break;
	}

	for (int i = 0; i < 9; i++)
	{
		if (arr[i] < 0)
			continue;
		cout << arr[i] << "\n";
	}


	return 0;
}