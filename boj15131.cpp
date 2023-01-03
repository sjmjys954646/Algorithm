#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <string>

using namespace std;

int cache[1000002];
int arr[10];

int main()
{
	arr[2] = 1;
	arr[3] = 7;
	arr[4] = 4;
	arr[5] = 5;
	arr[6] = 9;
	arr[7] = 8;

	cache[2] = 1;
	cache[3] = 7;
	cache[4] = 4;
	cache[5] = 8;
	cache[6] = 14;

	int N;

	cin >> N;

	for (int i = 7; i <= N; i++)
	{
		for (int j = 2; j < 8; j++)
		{
			cache[i] = max(cache[i], cache[i - j] + arr[j]);
		}
	}

	cout << cache[N];
	
	return 0;
}