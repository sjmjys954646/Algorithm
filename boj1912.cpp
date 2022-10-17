
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

using namespace std;

int Min(int a, int b)
{
	return a < b ? a : b;
}

int Max(int a, int b)
{
	return a < b ? b : a;
}



int main()
{
	int num;
	
	cin >> num;
	int arr[100001];
	int k = 0;
	int ans = -1001;
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < num; i++)
	{
		k = Max(0, k) + arr[i];
		ans = Max(k, ans);
	}

	cout << ans;

	return 0;
}