#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <string>

using namespace std;

int cache[1002];
int arr[1002];
int N;
int tmp;

int main()
{
	for (int i = 0; i <= 1001; i++)
		cache[i] = 986543210;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	cache[0] = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= arr[i]; j++)
		{
			cache[i + j] = min(cache[i+j],cache[i] + 1);
		}
	}


	if (cache[N - 1] == 986543210)
		cout << -1;
	else
		cout << cache[N - 1];

	return 0;
}