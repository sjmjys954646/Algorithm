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
	int mini[1004];
	int maxi[1004];
	int arr[1004];
	cin >> num;
	int ans = 0;

	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
		maxi[i] = 1;
		mini[i] = 1;
	}

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < i; j++) 
		{
			if (arr[j] < arr[i] && maxi[i] < maxi[j] + 1) 
			{
				maxi[i] = maxi[j] + 1;
			}
		}
	}

	for (int i = num - 1; i >= 0; i--)
	{
		for (int j = num - 1; j > i; j--)
		{
			if (arr[j] < arr[i] && mini[i] < mini[j] + 1)
			{
				mini[i] = mini[j] + 1;
			}
		}
	}

	for (int i = 0; i < num; i++)
	{
		ans = max(ans, maxi[i] + mini[i] - 1);
	}

	cout << ans;

	return 0;
}

