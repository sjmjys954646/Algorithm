#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <string>

using namespace std;

int N;
int arr[100002];
int cache[100002];
int ans = 1;

int main()
{

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];	
		cache[i] = 1;
	}


	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < i; ++j) 
		{
			if (arr[i] > arr[j]) 
			{
				cache[i] = max(cache[i], cache[j] + 1);
			}
			ans = max(ans, cache[i]);
		}
	}

	cout << ans;

	return 0;
}